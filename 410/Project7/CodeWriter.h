//
//  CodeWriter.h
//  Project7
//
//  Created by Eli Billinger on 4/1/22.
//

#ifndef CodeWriter_h
#define CodeWriter_h

#include <string>
#include <fstream>
#include <iostream>

class CodeWriter{
public:
    CodeWriter(std::string outputFile);
    
    void writeArithmetic(std::string command);
    void writePop(std::string segment, int index);
    void writePush(std::string segment, int index);
    
    void closeOutputFile();
    
private:
    std::ofstream outputStream;
    std::string outfile;
    int counter;
    
    void popToD();
    void pushFromD();
    void copyIntoD(int index);
    void copyDToValue(int index);
    
};

#endif /* CodeWriter_h */
