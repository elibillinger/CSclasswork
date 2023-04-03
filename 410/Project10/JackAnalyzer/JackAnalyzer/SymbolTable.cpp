//
//  SymbolTable.cpp
//  JackAnalyzer
//
//  Created by Eli Billinger on 5/4/22.
//

#include <stdio.h>
#include "SymbolTable.h"

SymbolTable::SymbolTable(){
    
}

SymbolRecord SymbolTable::get(std::string name){
    for(auto entry : localMap){
        if(entry.first == name) {
            return entry.second;
        }
        
    }
    for(auto entry : globalMap){
        if(entry.first == name) {
            return entry.second;
        }
    }
    return SymbolRecord("","",0);
}

void SymbolTable::put(std::string name, std::string type, std::string segment, int offset){
    SymbolRecord record = SymbolRecord("","",0);
    if(segment == "static"){
        record = SymbolRecord(type,segment,numStatic);
        numStatic++;
    } else if (segment == "argument"){
        record = SymbolRecord(type,segment,numArgument);
        numArgument++;
    } else if (segment == "local"){
        record = SymbolRecord(type,segment,numLocal);
        numLocal++;
    } else {
        record = SymbolRecord(type,"this",numField);
        numField++;
    }
    
    if(segment == "argument" || segment == "local"){
        localMap.insert(std::pair<std::string,SymbolRecord>(name,record));
    } else {
        
        globalMap.insert(std::pair<std::string,SymbolRecord>(name,record));
    }
}
    


bool SymbolTable::contains(std::string name){
    for(auto entry : localMap){
        if(entry.first == name) {
            return true;
        }
        
    }
    for(auto entry : globalMap){
        if(entry.first == name) {
            return true;
        }
    }
    
    return false;
}

void SymbolTable::clearLocal(){
    localMap.clear();
    numLocal = 0;
    numArgument = 0;
}
