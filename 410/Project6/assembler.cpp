#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <bitset>

std::map<std::string,int> symbolTable;
std::map<std::string,std::string> jumpTable;
std::map<std::string,std::string> destTable;
std::map<std::string,std::string> compTable;
int nextVariable = 16;

enum type {
    LTYPE,ATYPE,CTYPE,END
};

void initializeSymbolTable(){
    symbolTable.insert(std::pair<std::string,int>("R0",0));
    symbolTable.insert(std::pair<std::string,int>("R1",1));
    symbolTable.insert(std::pair<std::string,int>("R2",2));
    symbolTable.insert(std::pair<std::string,int>("R3",3));
    symbolTable.insert(std::pair<std::string,int>("R4",4));
    symbolTable.insert(std::pair<std::string,int>("R5",5));
    symbolTable.insert(std::pair<std::string,int>("R6",6));
    symbolTable.insert(std::pair<std::string,int>("R7",7));
    symbolTable.insert(std::pair<std::string,int>("R8",8));
    symbolTable.insert(std::pair<std::string,int>("R9",9));
    symbolTable.insert(std::pair<std::string,int>("R10",10));
    symbolTable.insert(std::pair<std::string,int>("R11",11));
    symbolTable.insert(std::pair<std::string,int>("R12",12));
    symbolTable.insert(std::pair<std::string,int>("R13",13));
    symbolTable.insert(std::pair<std::string,int>("R14",14));
    symbolTable.insert(std::pair<std::string,int>("R15",15));
    symbolTable.insert(std::pair<std::string,int>("SCREEN",16384));
    symbolTable.insert(std::pair<std::string,int>("KBD",24576));
    symbolTable.insert(std::pair<std::string,int>("SP",0));
    symbolTable.insert(std::pair<std::string,int>("LCL",1));
    symbolTable.insert(std::pair<std::string,int>("ARG",2));
    symbolTable.insert(std::pair<std::string,int>("THIS",3));
    symbolTable.insert(std::pair<std::string,int>("THAT",4));
}

void initializeJumpTable(){
    jumpTable.insert(std::pair<std::string,std::string>("null","000"));
    jumpTable.insert(std::pair<std::string,std::string>("JGT","001"));
    jumpTable.insert(std::pair<std::string,std::string>("JEQ","010"));
    jumpTable.insert(std::pair<std::string,std::string>("JGE","011"));
    jumpTable.insert(std::pair<std::string,std::string>("JLT","100"));
    jumpTable.insert(std::pair<std::string,std::string>("JNE","101"));
    jumpTable.insert(std::pair<std::string,std::string>("JLE","110"));
    jumpTable.insert(std::pair<std::string,std::string>("JMP","111"));
}
void initializeDestTable(){
    destTable.insert(std::pair<std::string,std::string>("null","000"));
    destTable.insert(std::pair<std::string,std::string>("M","001"));
    destTable.insert(std::pair<std::string,std::string>("D","010"));
    destTable.insert(std::pair<std::string,std::string>("DM","011"));
    destTable.insert(std::pair<std::string,std::string>("A","100"));
    destTable.insert(std::pair<std::string,std::string>("AM","101"));
    destTable.insert(std::pair<std::string,std::string>("AD","110"));
    destTable.insert(std::pair<std::string,std::string>("ADM","111"));
}
void initializeCompTable(){
    compTable.insert(std::pair<std::string,std::string>("0","101010"));
    compTable.insert(std::pair<std::string,std::string>("1","111111"));
    compTable.insert(std::pair<std::string,std::string>("-1","111010"));
    compTable.insert(std::pair<std::string,std::string>("D","001100"));
    compTable.insert(std::pair<std::string,std::string>("A","110000"));
    compTable.insert(std::pair<std::string,std::string>("M","110000"));
    compTable.insert(std::pair<std::string,std::string>("!D","001101"));
    compTable.insert(std::pair<std::string,std::string>("!A","110001"));
    compTable.insert(std::pair<std::string,std::string>("!M","110001"));
    compTable.insert(std::pair<std::string,std::string>("-D","001111"));
    compTable.insert(std::pair<std::string,std::string>("-A","110011"));
    compTable.insert(std::pair<std::string,std::string>("-M","110011"));
    compTable.insert(std::pair<std::string,std::string>("D+1","110011"));
    compTable.insert(std::pair<std::string,std::string>("A+1","110111"));
    compTable.insert(std::pair<std::string,std::string>("M+1","110111"));
    compTable.insert(std::pair<std::string,std::string>("D-1","001110"));
    compTable.insert(std::pair<std::string,std::string>("A-1","110010"));
    compTable.insert(std::pair<std::string,std::string>("M-1","110010"));
    compTable.insert(std::pair<std::string,std::string>("D+A","000010"));
    compTable.insert(std::pair<std::string,std::string>("D+M","000010"));
    compTable.insert(std::pair<std::string,std::string>("D-A","010011"));
    compTable.insert(std::pair<std::string,std::string>("D-M","010011"));
    compTable.insert(std::pair<std::string,std::string>("A-D","000111"));
    compTable.insert(std::pair<std::string,std::string>("M-D","000111"));
    compTable.insert(std::pair<std::string,std::string>("D&A","000000"));
    compTable.insert(std::pair<std::string,std::string>("D&M","000000"));
    compTable.insert(std::pair<std::string,std::string>("D|A","010101"));
    compTable.insert(std::pair<std::string,std::string>("D|M","010101"));
}

std::pair<type,std::string> getCommand(std::istream &input) {
    const std::string WHITESPACE = " \n\r\t\f\v";
    std::pair<type, std::string> command;
    std::string line;
    std::getline(input, line);
    std::size_t found = line.find("//");
    if (found != std::string::npos) {
        line.erase(found);
    }
    size_t start = line.find_first_not_of(WHITESPACE);
    line = (start == std::string::npos) ? "" : line.substr(start);
    size_t end = line.find_last_not_of(WHITESPACE);
    line =  (end == std::string::npos) ? "" : line.substr(0, end + 1);
    while(line.empty()){
        std::getline(input, line);
        found = line.find("//");
        if (found != std::string::npos) {
            line.erase(found);
        }
        start = line.find_first_not_of(WHITESPACE);
        line = (start == std::string::npos) ? "" : line.substr(start);
        end = line.find_last_not_of(WHITESPACE);
        line =  (end == std::string::npos) ? "" : line.substr(0, end + 1);
        if(input.eof()){
            command.first = END;
            command.second = " ";
            return command;
        }
    }
    if(line[0] == '@'){
        command.first = ATYPE;
    } else if(line[0] == '('){
        command.first = LTYPE;
    } else {
        command.first = CTYPE;
    }
    command.second = line;
    return command;
}


std::vector<std::pair<type,std::string> > firstPass(std::istream &input){
    int PC = 0;
    std::vector<std::pair<type,std::string> > commands;
    std::pair<type, std::string> command;
    while(command.first != END){
        command = getCommand(input);
        commands.push_back(command);
        if(command.first == LTYPE){
            std::string value;
            std::string temp = command.second.substr(1);
            int pos = temp.find(')');
            if(pos!=std::string::npos){
                std::string l = temp.substr(0,pos);
                value = l;
            }
            symbolTable.insert(std::pair<std::string,int>(value,PC));
        }
        PC++;
    }
    return commands;
}


int lookupSymbol(std::string s){
    for(const auto& pair : symbolTable){
        if(pair.first == s){
            return pair.second;
        }
    }
    return -1;
}

std::string translateA(std::pair<type,std::string> command){
    int num;
    std::string aValue = command.second.substr(1);
    std::string translatedA;
    if(isdigit(command.second[1])){
        num = stoi(aValue);
    } else {
        int tempNum = lookupSymbol(aValue);
        if(tempNum == -1){
            symbolTable.insert(std::pair<std::string,int>(aValue,nextVariable));
            num = nextVariable;
            nextVariable++;
        } else {
            num = tempNum;
        }
    }
    translatedA = "0" + std::bitset<15>(num).to_string();
    return translatedA;
}

std::string lookupJump(std::string s){
    for(const auto& pair : jumpTable){
        if(pair.first == s){
            return pair.second;
        }
    }
    return jumpTable["null"];
}

std::string lookupDest(std::string s){
    for(const auto& pair : destTable){
        if(pair.first == s){
            return pair.second;
        }
    }
    return destTable["null"];
}

std::string lookupComp(std::string s){
    for(const auto& pair : compTable){
        if(pair.first == s){
            return pair.second;
        }
    }
    return compTable["0"];
}

std::string translateC(std::pair<type,std::string> command){
    int posEqual = command.second.find("=");
    int posJump = command.second.find(";");
    std::string comp;
    std::string dest;
    std::string jump;

    if(posEqual!=std::string::npos){
        dest = command.second.substr(0,posEqual);
        if(posJump!=std::string::npos){
            jump = command.second.substr(posJump+1);
            comp = command.second.substr(posEqual+1,posJump-posEqual);
        } else {
            jump = "null";
            comp = command.second.substr((posEqual+1));
        }

    } else {
        dest = "null";
        if(posJump!=std::string::npos){
            jump = command.second.substr(posJump+1);
            comp = command.second.substr(posEqual+1,posJump-posEqual);
        } else {
            jump = "null";
            comp = command.second;
        }
    }
    std::string translatedString = "111" + lookupComp(comp) + lookupDest(dest) + lookupJump(jump);
    return translatedString;
}


std::string translate(std::pair<type,std::string> command){
    if(ATYPE == command.first){
        return translateA(command);
    } else if (command.first == CTYPE){
        return translateC(command);
    }
}


std::vector<std::string> secondPass(std::vector<std::pair<type,std::string> > commandList){
    nextVariable = 16;
    std::vector<std::string> binary;
    for (auto & command : commandList) {
        if(command.first != LTYPE && command.first != END){
            binary.push_back(translate(command));
        }
    }
    return binary;
}

int main(int argc, char** argv) {
    if(argc != 2){
        std::cout << "usage: assembler prog.asm" << std::endl;
        return -1;
    }
    initializeSymbolTable();
    initializeCompTable();
    initializeDestTable();
    initializeJumpTable();
    std::vector<std::pair<type,std::string> > commandList;
    std::string input_file = argv[1];
    int pos = input_file.find('.');
    std::string output = input_file.substr(0,pos);
    output = output + ".hack";
    std::ofstream fileout(output);
    std::ifstream input;
    input.open(input_file);
    if(!input){
        std::cout << "file not found";
    }
    std::vector<std::string> binaryStrings = secondPass(firstPass(input));
    for(const auto& string : binaryStrings){
        fileout << string << std::endl;
    }
    input.close();
    fileout.close();
    return 0;
}

