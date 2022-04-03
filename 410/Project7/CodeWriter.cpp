//
//  CodeWriter.cpp
//  Project7
//
//  Created by Eli Billinger on 4/1/22.
//

#include <stdio.h>
#include "CodeWriter.h"

CodeWriter::CodeWriter(std::string outputFile){
    outputStream.open(outputFile);
    outfile = outputFile;
    counter = 0;
}

void CodeWriter::writeArithmetic(std::string command){
    if(command == "add"){ //addition
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=M+D" << std::endl;
        pushFromD();
    } else if (command == "sub"){ //subtraction
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=D-M" << std::endl;
        pushFromD();
    } else if (command == "neg"){
        popToD();
        outputStream << "D=-D" << std::endl;
        pushFromD();
    } else if(command == "lt"){
        std::string uniqueLabel = "LABEL" + std::to_string(counter);//generate unique label
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=D-M" << std::endl;
        outputStream << "@" + uniqueLabel << std::endl;
        outputStream << "D;JLT" << std::endl;
        outputStream << "D=0" << std::endl;
        outputStream << "@" + uniqueLabel+"_END" << std::endl;
        outputStream << "0;JMP" << std::endl;
        outputStream << "("+uniqueLabel+")" << std::endl;
        outputStream << "D=-1" << std::endl;
        outputStream << "("+uniqueLabel+"_END)" << std::endl;
        pushFromD();
        counter++;
    } else if(command == "gt"){
        std::string uniqueLabel = "LABEL" + std::to_string(counter);//generate unique label
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=D-M" << std::endl;
        outputStream << "@" + uniqueLabel << std::endl;
        outputStream << "D;JGT" << std::endl;
        outputStream << "D=0" << std::endl;
        outputStream << "@" + uniqueLabel+"_END" << std::endl;
        outputStream << "0;JMP" << std::endl;
        outputStream << "("+uniqueLabel+")" << std::endl;
        outputStream << "D=-1" << std::endl;
        outputStream << "("+uniqueLabel+"_END)" << std::endl;
        pushFromD();
        counter++;
    } else if(command == "eq"){
        std::string uniqueLabel = "LABEL" + std::to_string(counter);//generate unique label
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=D-M" << std::endl;
        outputStream << "@" + uniqueLabel << std::endl;
        outputStream << "D;JEQ" << std::endl;
        outputStream << "D=0" << std::endl;
        outputStream << "@" + uniqueLabel+"_END" << std::endl;
        outputStream << "0;JMP" << std::endl;
        outputStream << "("+uniqueLabel+")" << std::endl;
        outputStream << "D=-1" << std::endl;
        outputStream << "("+uniqueLabel+"_END)" << std::endl;
        pushFromD();
        counter++;
    } else if (command == "not"){
        popToD();
        outputStream << "D=!D" << std::endl;
        pushFromD();
    } else if (command == "or"){
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=M|D" << std::endl;
        pushFromD();
    } else if(command == "and"){
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "D=M&D" << std::endl;
        pushFromD();
    }
}


void CodeWriter::writePop(std::string segment, int index){
    if (segment == "local"){
        outputStream << "@LCL" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "D=D+A" << std::endl;
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "A=M" << std::endl;
        outputStream << "M=D" << std::endl;
    } else if (segment == "argument"){
        outputStream << "@ARG" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "D=D+A" << std::endl;
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "A=M" << std::endl;
        outputStream << "M=D" << std::endl;
    } else if (segment == "this"){
        outputStream << "@THIS" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "D=D+A" << std::endl;
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "A=M" << std::endl;
        outputStream << "M=D" << std::endl;
    } else if (segment == "that"){
        outputStream << "@THAT" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "D=D+A" << std::endl;
        outputStream << "@R13" << std::endl;
        outputStream << "M=D" << std::endl;
        popToD();
        outputStream << "@R13" << std::endl;
        outputStream << "A=M" << std::endl;
        outputStream << "M=D" << std::endl;
    } else if (segment == "temp"){
        popToD();
        int value = 5 + index;
        outputStream << "@"<<std::to_string(value) << std::endl;
        outputStream << "M=D" << std::endl;
    } else if (segment == "pointer"){
        popToD();
        int value = 3 + index;
        outputStream << "@"<<std::to_string(value) << std::endl;
        outputStream << "M=D" << std::endl;
    } else if (segment == "static"){
        popToD();
        auto pos = outfile.find(".");
        std::string output = outfile.substr(0,pos);
        outputStream << "@"<< output << "."<< std::to_string(index) << std::endl;
        outputStream << "M=D" << std::endl;
    }
}

void CodeWriter::writePush(std::string segment, int index){
    if (segment == "constant") {
        copyIntoD(index);
        pushFromD();
    } else if (segment == "local"){
        outputStream << "@LCL" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "A=D+A" << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    } else if (segment == "argument"){
        outputStream << "@ARG" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "A=D+A" << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    } else if (segment == "this"){
        outputStream << "@THIS" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "A=D+A" << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    } else if (segment == "that"){
        outputStream << "@THAT" << std::endl;
        outputStream << "D=M" << std::endl;
        outputStream << "@" << std::to_string(index) << std::endl;
        outputStream << "A=D+A" << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    } else if (segment == "temp"){
        int value = 5 + index;
        outputStream << "@"<<std::to_string(value) << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    } else if (segment == "pointer"){
        int value = 3 + index;
        outputStream << "@"<<std::to_string(value) << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    } else if (segment == "static"){
        auto pos = outfile.find(".");
        std::string output = outfile.substr(0,pos);
        outputStream << "@"<< output << "."<< std::to_string(index) << std::endl;
        outputStream << "D=M" << std::endl;
        pushFromD();
    }
    
}

void CodeWriter::popToD(){
    //Decrement value in SP
    outputStream << "@SP" << std::endl;
    outputStream << "M=M-1" << std::endl;
    
    //Copy vale from SP into D
    outputStream << "A=M" << std::endl;
    outputStream << "D=M" << std::endl;
}

void CodeWriter::pushFromD(){
    // Copy value from D into next available stack location
    outputStream << "@SP" << std::endl;
    outputStream << "A=M" << std::endl;
    outputStream << "M=D" << std::endl;
    
    //increment value in SP
    outputStream << "@SP" << std::endl;
    outputStream << "M=M+1" << std::endl;
    
}

void CodeWriter::copyIntoD(int index){
    outputStream << "@"<< index << std::endl;
    outputStream << "D=A" << std::endl;
}

void CodeWriter::closeOutputFile(){
    outputStream.close();
}
