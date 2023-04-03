//
//  SymbolRecord.cpp
//  JackAnalyzer
//
//  Created by Eli Billinger on 5/4/22.
//

#include <stdio.h>
#include "SymbolRecord.h"

SymbolRecord::SymbolRecord(std::string symbol_type, std::string symbol_segment, int symbol_offset){
    type = symbol_type;
    segment = symbol_segment;
    offset = symbol_offset;
}
