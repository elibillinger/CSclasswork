//
//  main.cpp
//  Project7
//
//  Created by Eli Billinger on 3/31/22.
//

#include <iostream>
#include "Parser.h"
#include "CodeWriter.h"

int main(int argc, const char* argv[]) {
    //Get input file from command line and get filename without filetype
    std::string input_file = argv[1];
    auto pos = input_file.find(".");
    std::string output = input_file.substr(0,pos);
    std::string fileType = input_file.substr(pos);
    //check file type
    if(fileType != ".vm"){
        std::cout << "Wrong file type. Must be .vm" << std::endl;
    }
    //create name for output file
    output = output + ".asm";
    
    //Construct Parser
    Parser* parser = new Parser(input_file);
    CodeWriter* codeWriter = new CodeWriter(output);
    
    //Go through all commands in the file
    bool getCommand = true;
    while(getCommand){
        // Call code writer
        std::pair<CommandType,std::string> command = parser->getCommand();
        if (command.first == CommandType::END) {
            getCommand = false;
            break;
        }
        switch (command.first) {
            case CommandType::C_ARITHMATIC:
                codeWriter->writeArithmetic(parser->getArg1());
                break;
            case CommandType::C_PUSH:
                codeWriter->writePush( parser->getArg1(), parser->getArg2());
                break;
            case CommandType::C_POP:
                codeWriter->writePop( parser->getArg1(), parser->getArg2());
            default:
                break;
//            case CommandType::C_LABEL:
//                <#code#>
//                break;
//            case CommandType::C_GOTO:
//                <#code#>
//                break;
//            case CommandType::C_IF:
//                <#code#>
//                break;
//            case CommandType::C_FUNCTION:
//                <#code#>
//                break;
//            case CommandType::C_RETURN:
//                <#code#>
//                break;
//            case CommandType::C_CALL:
//                <#code#>
//                break;
//            case CommandType::END:
//                <#code#>
//                break;
        }
        //std::cout << command.second << std::endl;
    }
//    for(const auto& string : binaryStrings){
//        fileout << string << std::endl;
//    }
    
    parser->closeInputFile();
    codeWriter->closeOutputFile();
    return 0;
}
