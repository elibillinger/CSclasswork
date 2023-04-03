//
//  SymbolTable.h
//  JackAnalyzer
//
//  Created by Eli Billinger on 5/4/22.
//

#ifndef SymbolTable_h
#define SymbolTable_h
#include <string>
#include <map>
#include "SymbolRecord.h"

class SymbolTable
{
public:
    SymbolTable();
    
    SymbolRecord get(std::string name);
    void put(std::string name,std::string type, std::string segment, int offset);
    bool contains(std::string name);
    void clearLocal();
    int getField() {return numField;};
    
private:
    std::map<std::string,SymbolRecord> localMap;
    std::map<std::string,SymbolRecord> globalMap;
    
    int numLocal = 0;
    int numArgument = 0;
    int numStatic = 0;
    int numField = 0;
    

};

#endif /* SymbolTable_h */
