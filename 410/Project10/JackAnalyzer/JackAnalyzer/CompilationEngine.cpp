//
//  CompilationEngine.cpp
//  JackAnalyzer
//
//  Created by Eli Billinger on 5/3/22.
//

#include <stdio.h>
#include "CompilationEngine.h"


CompilationEngine::CompilationEngine(std::vector<std::string> tokens,std::vector<std::string> tokensXML, std::string output){
    tokenList = tokens;
    tokensListXML = tokensXML;
    
    symbolTable = SymbolTable();
    
    
    output = "My"+output+ ".vm";
    outputStream.open(output);
    outfile = output;
}


void CompilationEngine::compile(){
    if(tokenList[0] == "class"){
        compileClass();
    }
}

void CompilationEngine::compileClass(){
    
    //add class overall output
    paresedList.push_back("<class>");
    //add class
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //add classname
    className = tokenList[position];
    paresedList.push_back(tokensListXML[position]);
    position++;
    //add {
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    compileClassVarDec();
    compileSubroutine();
    
    //add }
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    paresedList.push_back("</class>");
}

void CompilationEngine::compileClassVarDec(){
    
    if(tokenList[position] == "}"){
        return;
    }
    
    std::string segment;
    std::string type;
    std::string name;
    
    if(tokenList[position] == "static" || tokenList[position] == "field"){
        paresedList.push_back("<classVarDec>");
        segment = tokenList[position];
        paresedList.push_back(tokensListXML[position]);
        position++;
        
    } else {
        return;
    }
    
    type = compileType();
    
    while(true){
        //add varName
        name = tokenList[position];
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        symbolTable.put(name, type, segment, 0);
        
        if(tokenList[position] == ","){
            //add ,
            paresedList.push_back(tokensListXML[position]);
            position++;
        } else {
            // add ;
            paresedList.push_back(tokensListXML[position]);
            position++;
            break;
        }
    }
    
    paresedList.push_back("</classVarDec>");
    
    compileClassVarDec();
}

void CompilationEngine::compileSubroutine(){
    
    if(tokenList[position] == "}"){
        return;
    }
    
    symbolTable.clearLocal();
    
    std::string type;
    paresedList.push_back("<subroutineDec>");
    
    // output keyword tag for constructor/function, or method
    if(tokenList[position] == "method"){
        symbolTable.put("this",className,"argument",0);
    }
    keyword = tokenList[position];
    
    
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    
    if(tokenList[position] == "void"){
        //add void
        paresedList.push_back(tokensListXML[position]);
        position++;
    } else {
    //parse the type
    type = compileType();
    }
    
    //output subroutineName
    functionName = tokenList[position];
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //output (
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //parse List
    compileParameterList();
    
    //output )
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //parse subroutine body
    compileSubroutineBody();
    
    paresedList.push_back("</subroutineDec>");
    
    compileSubroutine();
}

void CompilationEngine::compileParameterList(){
    
    
    if(tokenList[position] == ")"){
        paresedList.push_back("<parameterList>");
        paresedList.push_back("</parameterList>");
        return;
    }
    paresedList.push_back("<parameterList>");
    
    while (true) {
        std::string type;
        type = compileType();
        //add varName
        std::string name;
        name = tokenList[position];
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        symbolTable.put(name, type, "argument", 0);
        
        if(tokenList[position] == ","){
            //add ,
            paresedList.push_back(tokensListXML[position]);
            position++;
        } else {
            break;
        }
    }
    
    paresedList.push_back("</parameterList>");
    
}

void CompilationEngine::compileSubroutineBody(){
    paresedList.push_back("<subroutineBody>");
    //output {
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    if(tokenList[position] == "var"){
        compileVarDec();
    }
   
    vmList.push_back("function "+ className +"."+functionName + " " + std::to_string(numLocal));
    numLocal = 0;
    
    //std::cout << keyword << std::endl;
    if(keyword == "method"){
        vmList.push_back("push argument 0");
        vmList.push_back("pop pointer 0");
    } else if (keyword == "constructor"){
        int temp = symbolTable.getField();
        vmList.push_back("push constant " +std::to_string(temp));
        vmList.push_back("call Memory.alloc 1");
        vmList.push_back("pop pointer 0");
    }
    
    paresedList.push_back("<statements>");
    compileStatements();
    paresedList.push_back("</statements>");
    
    //output }
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    paresedList.push_back("</subroutineBody>");
}

void CompilationEngine::compileVarDec(){
    
    
    if(tokenList[position] == "var"){
        paresedList.push_back("<varDec>");
        paresedList.push_back(tokensListXML[position]);
        position++;
    } else {
        return;
    }
    std::string type;
    
    type = compileType();
    
    while(true){
        std::string name;
        
        //add varName
        name = tokenList[position];
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        symbolTable.put(name, type, "local", 0);
        numLocal++;
        
        if(tokenList[position] == ";"){
            //add ;
            paresedList.push_back(tokensListXML[position]);
            position++;
            break;
        }
        //add ,
        paresedList.push_back(tokensListXML[position]);
        position++;
    }
    
    paresedList.push_back("</varDec>");
    
    compileVarDec();
}

void CompilationEngine::compileStatements(){
    
    if(tokenList[position] == "let"){
        compileLet();
        compileStatements();
    } else if (tokenList[position] == "if") {
        compileIf();
        compileStatements();
    } else if(tokenList[position] == "while"){
        compileWhile();
        compileStatements();
    } else if(tokenList[position] == "do"){
        compileDo();
        compileStatements();
    } else if (tokenList[position] == "return"){
        compileReturn();
        compileStatements();
    } else if(tokenList[position] == "}"){
        return;
    }

    
    
}

void CompilationEngine::compileLet(){
    paresedList.push_back("<letStatement>");
    bool exp = false;
    // add let
    paresedList.push_back(tokensListXML[position]);
    position++;
    // add varName
    std::string varName = tokenList[position];
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    if(tokenList[position] == "["){
        exp = true;
        
        // add [
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        SymbolRecord record = symbolTable.get(varName);
        vmList.push_back("push "+record.segment + " " + std::to_string(record.offset));
        
        compileExpression();
        
        //add ]
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        vmList.push_back("add");
    }
    

    //add =
    paresedList.push_back(tokensListXML[position]);
    position++;
        
    compileExpression();
    
    //add ;
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    if(exp){
        vmList.push_back("pop temp 0");
        vmList.push_back("pop pointer 1");
        vmList.push_back("push temp 0");
        vmList.push_back("pop that 0");
        
    } else {
        //pop
        SymbolRecord record = symbolTable.get(varName);
        vmList.push_back("pop "+record.segment + " " + std::to_string(record.offset));
    }
    
    
    
    paresedList.push_back("</letStatement>");
}

void CompilationEngine::compileIf(){
    paresedList.push_back("<ifStatement>");
    int counter = globalCounter;
    globalCounter++;
    
    // add if
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //add (
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    compileExpression();
    
    //vmList.push_back("not");
    vmList.push_back("if-goto IF_FALSE_" + std::to_string(counter));
    
    //add )
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //add {
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //statement
    paresedList.push_back("<statements>");
    compileStatements();
    paresedList.push_back("</statements>");
    
    vmList.push_back("goto IF_END_" + std::to_string(counter));
    vmList.push_back("label IF_FALSE_" + std::to_string(counter));
    
    //add }
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    if(tokenList[position] == "else"){
        //add else
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        //add {
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        //statement
        paresedList.push_back("<statements>");
        compileStatements();
        paresedList.push_back("</statements>");
        
        //add }
        paresedList.push_back(tokensListXML[position]);
        position++;
    }
    
    vmList.push_back("label IF_END_" + std::to_string(counter));
    //globalCounter++;
    paresedList.push_back("</ifStatement>");
}

void CompilationEngine::compileWhile(){
    paresedList.push_back("<whileStatement>");
    
    int counter = globalCounter;
    globalCounter++;
    
    //add while
    paresedList.push_back(tokensListXML[position]);
    position++;
    //add (
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    vmList.push_back("label WHILE" + std::to_string(counter));
    
    compileExpression();
    
    vmList.push_back("not");
    vmList.push_back("if-goto WHILE_END" + std::to_string(counter));

    
    //add )
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //add {
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    paresedList.push_back("<statements>");
    compileStatements();
    paresedList.push_back("</statements>");
    
    // while goto
    vmList.push_back("goto WHILE" + std::to_string(counter));
    vmList.push_back("label WHILE_END" + std::to_string(counter));

    //add }
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    //globalCounter++;
    
    paresedList.push_back("</whileStatement>");
}

void CompilationEngine::compileDo(){
    paresedList.push_back("<doStatement>");
    //add Do
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    compileSubroutineCall();
    
    vmList.push_back("pop temp 0");
    // add ;
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    paresedList.push_back("</doStatement>");
}

void CompilationEngine::compileReturn(){
    paresedList.push_back("<returnStatement>");
    
    //add return
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    if(tokenList[position] == ";"){
        //add ;
        paresedList.push_back(tokensListXML[position]);
        position++;
        vmList.push_back("push constant 0");
        //vmList.push_back("return");
        
    } else {
        compileExpression();
        //add ;
        paresedList.push_back(tokensListXML[position]);
        position++;
    }
    vmList.push_back("return");
    
    
    paresedList.push_back("</returnStatement>");
}

void CompilationEngine::compileExpression(){
    paresedList.push_back("<expression>");
    
    compileTerm();
    
    
    
    while(true){
        //binary operator
        std::string op;
        if(tokenList[position] == "<" || tokenList[position] == ">" || tokenList[position] == "&" || tokenList[position] == "+" || tokenList[position] == "-" || tokenList[position] == "*" || tokenList[position] == "=" || tokenList[position] == "/" || tokenList[position] == "|"){
            if(tokenList[position] == "<"){
                tokenList[position] = "&lt;";
                op = "lt";
            } else if(tokenList[position] == ">"){
                tokenList[position] = "&gt;";
                op = "gt";
            } else if(tokenList[position] == "&"){
                tokenList[position] = "&amp;";
                op = "and";
            } else if(tokenList[position] == "+"){
                op = "add";
            } else if(tokenList[position] == "-"){
                op = "sub";
            } else if(tokenList[position] == "="){
                op = "eq";
            }else if(tokenList[position] == "*"){
                op = "call Math.multiply 2";
            } else if(tokenList[position] == "/"){
                op = "call Math.divide 2";
            }else if(tokenList[position] == "|"){
                op = "or";
            }
            
            //add the operator
            paresedList.push_back(tokensListXML[position]);
            position++;
            
            compileTerm();
            vmList.push_back(op);
        } else {
            break;
        }
    }
    
    
    
    paresedList.push_back("</expression>");
}

void CompilationEngine::compileTerm(){
    //paresedList.push_back("<term>");
    std::string tokenType;
    
    size_t find = tokensListXML[position].find_first_of(WHITESPACE);
    if(find != std::string::npos){
       tokenType  = tokensListXML[position].substr(0,find);
    }
    
    
    // check if varName | varName[expression] | subroutineCall
    if(tokenType == "<identifier>"){
        int temp_postion = position;
        position++;
        if(tokenList[position] == "["){
            position = temp_postion;
            //add varName
            std::string varName;
            varName = tokenList[position];
            paresedList.push_back(tokensListXML[position]);
            position++;
            
            SymbolRecord record = symbolTable.get(varName);
            vmList.push_back("push "+record.segment + " " + std::to_string(record.offset));
            
            //add [
            paresedList.push_back(tokensListXML[position]);
            position++;
            
            compileExpression();
            
            vmList.push_back("add");
            vmList.push_back("pop pointer 1");
            vmList.push_back("push that 0");
            
            
            //add ]
            paresedList.push_back(tokensListXML[position]);
            position++;
        } else if (tokenList[position] == "(" || tokenList[position] == "."){
            position = temp_postion;
            compileSubroutineCall();
        } else {
            position = temp_postion;
            //add varName
            std::string varName;
            varName = tokenList[position];
            paresedList.push_back(tokensListXML[position]);
            position++;
            SymbolRecord record = symbolTable.get(varName);
            vmList.push_back("push "+record.segment + " " + std::to_string(record.offset));
        }
        
        
    } else {
        if(tokenList[position] == "("){
            //add (
            paresedList.push_back(tokensListXML[position]);
            position++;
            
            compileExpression();
            
            //add )
            paresedList.push_back(tokensListXML[position]);
            position++;
        } else if(tokenList[position] == "-" || tokenList[position] == "~"){
            
            
            if(tokenList[position] == "-"){
                position++;
                compileTerm();
                vmList.push_back("neg");
            } else {
                position++;
                compileTerm();
                vmList.push_back("not");
            }
            
            
            //add unaryop
//            paresedList.push_back(tokensListXML[position]);
//            position++;
            
            
        } else {
            size_t find = tokensListXML[position].find_first_of(WHITESPACE);
            if(find != std::string::npos){
               tokenType  = tokensListXML[position].substr(0,find);
            }
            if(tokenType == "<stringConstant>"){
                std::string stringConst = tokenList[position];
                vmList.push_back("push constant "+ std::to_string(stringConst.size()+1));
                vmList.push_back("call String.new 1");
                
                for (int i = 0; i <= stringConst.size(); i++){
                    vmList.push_back("push constant "+ std::to_string((int)stringConst[i]));
                    vmList.push_back("call String.appendChar 2");
                }
                
                
            } else if (tokenType == "<integerConstant>"){
                vmList.push_back("push constant " + tokenList[position]);
            }else {
                if(tokenList[position] == "true"){
                    vmList.push_back("push constant 0");
                    vmList.push_back("not");

                } else if (tokenList[position] == "this"){
                    vmList.push_back("push pointer 0");

                } else {
                    vmList.push_back("push constant 0");
                }
            }
            
            
            // add int or string or keyword
            paresedList.push_back(tokensListXML[position]);
            position++;
            
        }
    }
    
    paresedList.push_back("</term>");
}

int CompilationEngine::compileExpressionList(){
    int counter = 0;
    paresedList.push_back("<expressionList>");
    
    if(tokenList[position] != ")"){
        counter = 1;
    compileExpression();
    while(true){
        if(tokenList[position] == ","){
            //add ,
            paresedList.push_back(tokensListXML[position]);
            position++;
            compileExpression();
            counter += 1;
        } else {
            break;
        }
    }
    }
    
    paresedList.push_back("</expressionList>");
    return counter;
}

std::string CompilationEngine::compileType(){
    //add type
    std::string type = tokenList[position];
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    return type;
}


void CompilationEngine::compileSubroutineCall(){
    std::string subroutineName;
    int numArgs = 0;
    //add subroutine name
    subroutineName = tokenList[position];
    paresedList.push_back(tokensListXML[position]);
    position++;
    
    if(tokenList[position] == "("){
        //push object
        vmList.push_back("push pointer 0");
        // add (
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        numArgs = compileExpressionList() +1;
        
        //add )
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        
        //write call
        vmList.push_back("call "+ className +"."+subroutineName + " " + std::to_string(numArgs));
        
    } else if( tokenList[position] == "."){
        
        //check if var or class name
        if(symbolTable.contains(subroutineName)){
            numArgs = 1;
            SymbolRecord record = symbolTable.get(subroutineName);
            
            vmList.push_back("push "+record.segment + " " + std::to_string(record.offset));
        } else {
            //subroutineName = className;
        }
        
        // add .
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        //add subroutine name
        std::string sub;
        sub = tokenList[position];
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        //add "("
        paresedList.push_back(tokensListXML[position]);
        position++;
        
        numArgs += compileExpressionList();
        
        
        subroutineName[0] = toupper(subroutineName[0]);
        if(subroutineName == "Game"){
            subroutineName = previous;
        } else {
            previous = subroutineName;
        }
        vmList.push_back("call "+ subroutineName +"."+sub + " " + std::to_string(numArgs));
        
        numArgs = 0;
        // add ")"
        paresedList.push_back(tokensListXML[position]);
        position++;
    }
    
    
    
}

std::vector<std::string> CompilationEngine::printXMLFile(){
//    for(auto xmlOutputs: paresedList){
//        outputStream << xmlOutputs << std::endl;
//    }
    
    for(auto output: vmList){
        outputStream << output << std::endl;
    }
    return vmList;
}

void CompilationEngine::closeOutputFile(){
    outputStream.close();
}
