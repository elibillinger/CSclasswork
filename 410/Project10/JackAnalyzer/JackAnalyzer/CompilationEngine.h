//
//  CompilationEngine.h
//  JackAnalyzer
//
//  Created by Eli Billinger on 5/3/22.
//

#ifndef CompilationEngine_h
#define CompilationEngine_h
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <iostream>
#include "SymbolTable.h"


class CompilationEngine
{
public:
    CompilationEngine(std::vector<std::string> tokens,std::vector<std::string> tokensXML,std::string output);
    
    void compile();
    
    void compileClass();
    void compileClassVarDec();
    void compileSubroutine();
    void compileParameterList();
    void compileSubroutineBody();
    void compileVarDec();
    void compileStatements();
    void compileLet();
    void compileIf();
    void compileWhile();
    void compileDo();
    void compileReturn();
    void compileExpression();
    void compileTerm();
    int compileExpressionList();
    std::string compileType();
    void compileSubroutineCall();
    
    
    std::vector<std::string> printXMLFile();
    void closeOutputFile();
    
private:
    
    SymbolTable symbolTable;
    
    std::ofstream outputStream;
    std::string outfile;
    std::string className;
    std::string functionName;
    std::string keyword;
    std::string previous;
    
    int position = 0;
    int globalCounter = 0;
    int numLocal = 0;
    
    const std::string WHITESPACE = " \n\r\t\f\v";

    
    std::vector<std::string> tokenList;
    std::vector<std::string> tokensListXML;
    
    std::vector<std::string> paresedList;
    std::vector<std::string> vmList;
};

#endif /* CompilationEngine_h */
