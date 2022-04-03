//
//  Parser.h
//  Project7
//
//  Created by Eli Billinger on 4/1/22.
//

#ifndef Parser_h
#define Parser_h

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

enum class CommandType{
    C_ARITHMATIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL,
    END
};


class Parser
{
public:
    Parser(std::string input);
    
    std::pair<CommandType,std::string> getCommand();
    
    void closeInputFile();
    
    std::string getArg1();
    
    int getArg2();
    
private:
    std::ifstream _inputStream;
    
    CommandType getCommandType(std::string command);
    
    std::vector<std::string> currentCommand;
};

#endif /* Parser_h */
