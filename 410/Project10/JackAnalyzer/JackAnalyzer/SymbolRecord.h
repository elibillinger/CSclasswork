//
//  SymbolRecord.h
//  JackAnalyzer
//
//  Created by Eli Billinger on 5/4/22.
//

#ifndef SymbolRecord_h
#define SymbolRecord_h
#include <string>

class SymbolRecord
{
public:
    SymbolRecord(std::string type, std::string segment, int offset);
    std::string type;
    std::string segment;
    int offset;
};
#endif /* SymbolRecord_h */
