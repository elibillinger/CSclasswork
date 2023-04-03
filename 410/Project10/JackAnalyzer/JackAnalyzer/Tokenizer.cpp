//
//  Tokenizer.cpp
//  JackAnalyzer
//
//  Created by Eli Billinger on 4/18/22.
//

#include <stdio.h>
#include "Tokenizer.h"
#include <algorithm>
#include <cctype>
#include <ctype.h>


Tokenizer::Tokenizer(std::string input){
    
    fileString = "";
    
    //opens input file
    _inputStream.open(input);
    if(!_inputStream){
        std::cout << "file not found"<< std::endl;
    } else {
        readFile();
    }
}



void Tokenizer::readFile(){
    //loop through file and add line to one string
    for( std::string line; getline( _inputStream, line ); )
    {
        //check if line is a comment and delete it if it is
        std::size_t findComment = line.find("//");
        if (findComment != std::string::npos) {
            line.erase(findComment);
        }
        
        //checks if string is empty or contains only whitespace
        //does not add it to string if it does
        bool blank = false;
        if (line.empty() || std::all_of(line.begin(), line.end(), [](char c){return std::isspace(c);})) {
              blank = true;
        }
        if(!blank){
            fileString += line;
        }
    }
    //find multi-line comment in file string
    std::size_t findComment = fileString.find("/*");
    if (findComment != std::string::npos) {
        std::size_t findComment2 = fileString.find("*/");
        if (findComment2 != std::string::npos) {
            fileString.erase(findComment,findComment2+2);
        }
    }
    parsedString = fileString;
    //std::cout << fileString << std::endl;
}



std::vector<std::string> Tokenizer::getTokens(){
    while (parsedString.length() >= 1 ){
        //std::cout << parsedString.length() << std::endl;
        tokenList.push_back(next());
    }
//    tokenList.push_back(next());
//    tokenList.push_back(next());

    toString();
    return tokenStringList;
}

std::pair<Token,std::string> Tokenizer::peek(){
    std::pair<Token,std::string> token;
    //get to no whitespace
    size_t next_token_start = parsedString.find_first_not_of(WHITESPACE);
    if(next_token_start != std::string::npos){
        parsedString = parsedString.substr(next_token_start);
    }
    if(parsedString[0] == ' '){
        parsedString = parsedString.substr(1);
    }
    
    if(parsedString[0] == '/' && parsedString[1] == '*'){
        size_t find_comment = parsedString.find("*/");
        if(find_comment != std::string::npos){
            parsedString = parsedString.substr(find_comment+2);
        }
    }
    //check for symbol
    size_t find_symbol = symbol_str.find(parsedString[0]);
    if (find_symbol != std::string::npos) {
        token.first = Token::SYMBOL;
        token.second = parsedString[0];
        return token;
    }
    
    //check for keywords
    for(auto keyword : keywords){
        size_t find_keyword = parsedString.find(keyword);
        if(find_keyword == 0){
            token.first = Token::KEYWORD;
            token.second = keyword;
            return token;
        }
    }
    
    //ckeck for integer constants
    size_t find_integer_constant = parsedString.find_first_of("0123456789");
    if(find_integer_constant == 0){
        size_t find_end_integer = parsedString.find_first_not_of("0123456789");
        token.first = Token::INTEGERCONSTANT;
        token.second = parsedString.substr(0,find_end_integer);
        return token;
    }
    
    //check for string constant
    size_t find_quote = parsedString.find("\"");
    if(find_quote == 0){
        std::string tempString = parsedString.substr(1);
        size_t find_end_quote = tempString.find_first_of("\"");
        token.first = Token::STRINGCONSTANT;
        token.second = parsedString.substr(1,find_end_quote);
        return token;
    }
    
    //check fot identifier
    size_t find_end = parsedString.find_first_of(symbol_str+" ");
    token.first = Token::IDENTIFIER;
    if(find_end == 0){
        token.first = Token::TEMP;
        token.second = parsedString.substr(0,find_end);
        return token;
    }
    token.second = parsedString.substr(0,find_end);
    return token;
}

std::pair<Token,std::string> Tokenizer::next(){
    std::pair<Token,std::string> token = peek();
    int moveStart = token.second.size();
    if (token.first == Token::STRINGCONSTANT) {
        moveStart += 2;
    }
   
    parsedString = parsedString.substr(moveStart);
    
    return token;
}

void Tokenizer::toString(){
    for(auto token: tokenList){
        
        if( !isspace(token.second[0])){
            std::string tokenString;
            std::string tokenType = tokenTypeToString(token.first);
            std::string tokenTemp = token.second;
            if(tokenTemp.back() == ' '){
                tokenTemp = tokenTemp.substr(0,tokenTemp.size()-1);
            }
            if(tokenType != "temp"){
            stringTokens.push_back(tokenTemp);
            }
            if(tokenTemp == "<"){
                tokenTemp = "&lt;";
            }
            if(tokenTemp == ">"){
                tokenTemp = "&gt;";
            }
            if(tokenTemp == "&"){
                tokenTemp = "&amp;";
            }
            tokenString += "<" + tokenType + "> ";
            tokenString += tokenTemp;
            tokenString += " </" + tokenType + ">";
            if(tokenType != "temp"){
                tokenStringList.push_back(tokenString);
            }
            
        }
    }
}

std::string Tokenizer::tokenTypeToString(Token token){
    if(token == Token::SYMBOL){
        return "symbol";
    } else if(token == Token::KEYWORD){
        return "keyword";
    } else if (token == Token::IDENTIFIER){
        return "identifier";
    } else if (token == Token::INTEGERCONSTANT){
        return "integerConstant";
    } else if (token == Token::TEMP){
        return "temp";
    } else {
        return "stringConstant";
    }
}

void Tokenizer::closeInputFile(){
    _inputStream.close();
}

