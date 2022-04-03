//
//  Parser.cpp
//  Project7
//
//  Created by Eli Billinger on 4/1/22.
//

#include <stdio.h>
#include "Parser.h"


Parser::Parser(std::string input){
    //opens input file
    _inputStream.open(input);
    if(!_inputStream){
        std::cout << "file not found"<< std::endl;
    }
}




std::pair<CommandType,std::string> Parser::getCommand() {
    if(currentCommand.size() != 0){
        currentCommand.clear();
    }
    
    
    const std::string WHITESPACE = " \n\r\t\f\v";
    std::pair<CommandType,std::string> command;
    std::string line;
    std::getline(_inputStream, line);
    std::size_t found = line.find("//");
    if (found != std::string::npos) {
        line.erase(found);
    }
    size_t start = line.find_first_not_of(WHITESPACE);
    line = (start == std::string::npos) ? "" : line.substr(start);
    size_t end = line.find_last_not_of(WHITESPACE);
    line =  (end == std::string::npos) ? "" : line.substr(0, end + 1);
    while(line.empty()){
        std::getline(_inputStream, line);
        found = line.find("//");
        if (found != std::string::npos) {
            line.erase(found);
        }
        start = line.find_first_not_of(WHITESPACE);
        line = (start == std::string::npos) ? "" : line.substr(start);
        end = line.find_last_not_of(WHITESPACE);
        line =  (end == std::string::npos) ? "" : line.substr(0, end + 1);
        if(_inputStream.eof()){
            command.first = CommandType::END;
            command.second = " ";
            return command;
        }
    }
    //Split line into strings
    std::string type;
    std::string restOfString;
    std::string arg1;
    std::string arg2;
    std::size_t findWhite = line.find(" ");
    //if no whitespace found it is a one word command
    if (findWhite == std::string::npos) {
        type = line;
        arg1 = line;
        arg2 = "";
    } else {
        type = line.substr(0,findWhite);
        restOfString = line.substr(findWhite+1);
        std::size_t findWhite2 = restOfString.find(" ");
        if(findWhite2 == std::string::npos){
            arg1 = restOfString;
            arg2 = "";
        } else {
            arg1 = restOfString.substr(0,findWhite2);
            arg2 = restOfString.substr(findWhite2+1);
        }
    }
    
    command.first = getCommandType(type);
    //add substrings into currentCommand vector
    currentCommand.push_back(type);
    currentCommand.push_back(arg1);
    currentCommand.push_back(arg2);
    command.second = line;
    return command;
}


CommandType Parser::getCommandType(std::string command){
    if (command == "push"){
        return CommandType::C_PUSH;
    } else if (command == "pop"){
        return CommandType::C_POP;
    } else {
        return CommandType::C_ARITHMATIC;
    }
    //TODO: Add other command types
    
}

std::string Parser::getArg1(){
    return currentCommand[1];
}

int Parser::getArg2(){
    return stoi(currentCommand[2]);
}

void Parser::closeInputFile(){
    _inputStream.close();
}
