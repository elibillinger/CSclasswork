//
//  Tokenizer.h
//  JackAnalyzer
//
//  Created by Eli Billinger on 4/18/22.
//

#ifndef Tokenizer_h
#define Tokenizer_h
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <iostream>

enum class Token{
    KEYWORD,
    SYMBOL,
    INTEGERCONSTANT,
    STRINGCONSTANT,
    IDENTIFIER,
    TEMP
};



class Tokenizer
{
public:
    Tokenizer(std::string input);
    
    void readFile();
    
    void closeInputFile();
    
    void createConstants();
    
    std::vector<std::string> getTokens();
    
    std::pair<Token,std::string> peek();
    std::pair<Token,std::string> next();
    
    void toString();
    
    std::string tokenTypeToString(Token token);
    
    std::vector<std::string> getTokenStrings() {return stringTokens;}
    
private:
    std::ifstream _inputStream;
    
    std::string fileString;
    std::string parsedString;
    
    std::vector<std::pair<Token,std::string>> tokenList;
    std::vector<std::string> tokenStringList;
    std::vector<std::string> stringTokens;
    
    std::string symbols[19] = {"{","}","(",")","[","]",".",",",";","+","*","/","&","|","<",">","=","~"};
    
    std::string symbol_str = "{}()[].,;+*/&|<>=~-";
    
    const std::string WHITESPACE = " \n\r\t\f\v";
    
    std::string keywords[21] = {"class","constructor","function","method","field","static","var","int","char","boolean","void","true","false","null","this","let","do","if","else","while","return"};
    
};

#endif /* Tokenizer_h */
