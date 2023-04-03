//
//  main.cpp
//  JackAnalyzer
//
//  Created by Eli Billinger on 4/18/22.
//

#include <iostream>
#include <filesystem>
#include "Tokenizer.h"
#include "CompilationEngine.h"
#include <iostream>


using namespace std;
namespace fs = std::filesystem;

int main(int argc, const char * argv[]) {
    
    if (argc != 2) {
            cout << "usage: " << argv[0] << " <filename or directory>" << endl;
            return -1;
        }

        fs::path p = argv[1];

        if (is_directory(p)) {
            cout << "contents of " << p.filename() << ":" << endl;
            std::string output = p.filename();
            output = output;
            
            for (auto const &entry: fs::directory_iterator(argv[1])) {
                if (is_regular_file(entry)) {
                    if (entry.path().extension() == ".jack") {
                        output = entry.path();
                        std::string temp = p.filename();
                        output = output.substr(temp.size()+1);
                        size_t find = output.find(".");
                        if(find != std::string::npos){
                            output = output.substr(0,find);
                        }
                        std::cout << output << std::endl;
                       // std::cout << entry.path() << std::endl;
                        fs::path jack_file = entry.path();
                        std::cout <<jack_file << std::endl;
                        Tokenizer* tokenizer = new Tokenizer(jack_file);
                        std::vector<std::string> tokenList = tokenizer->getTokens();
                        tokenizer->closeInputFile();
                        CompilationEngine* compilationEngine = new CompilationEngine(tokenizer->getTokenStrings(),tokenList,output);
                        compilationEngine->compile();
                        std::vector<std::string> vmList = compilationEngine->printXMLFile();
                        compilationEngine->closeOutputFile();
                        std::ofstream outputStream;
                        //output = "My" + output + "T.vm";
                        output = output + ".vm";
                        outputStream.open(output);
                        //outputStream << "<tokens>" << std::endl;
                        for(auto code : vmList){
                            outputStream << code << std::endl;
                        }
                        //outputStream << "</tokens>";
                    } else {
                        cout << "\t" << entry.path() << " - not a JACK file, ignore" << endl;
                    }
                }
            }
            
        } else if (fs::is_regular_file(argv[1])) {
            cout << p << " has stem: " << p.stem() << " and extension: " << p.extension() << endl;
            if (p.extension() == ".jack") {
                Tokenizer* tokenizer = new Tokenizer(p);
                std::vector<std::string> tokenList = tokenizer->getTokens();
                tokenizer->closeInputFile();
                std::ofstream outputStream;
                std::string output = p.stem();
                CompilationEngine* compilationEngine = new CompilationEngine(tokenizer->getTokenStrings(),tokenList,output);
                compilationEngine->compile();
                std::vector<std::string> vmList = compilationEngine->printXMLFile();
                compilationEngine->closeOutputFile();
                output = "My" + output + ".vm";
                outputStream.open(output);
                //outputStream << "<tokens>" << std::endl;
                for(auto code : vmList){
                    outputStream << code << std::endl;
                }
                //outputStream << "</tokens>";
            }
        } else {
            cout << "\"" << argv[1] << "\" is not a file or directory, or does not exist." << endl;
            return -1;
        }
    
    
    
    
    
//    //Get input file from command line and get filename without filetype
//    std::string input_file = argv[1];
//    auto pos = input_file.find(".");
//    std::string output = input_file.substr(0,pos);
//    std::string fileType = input_file.substr(pos);
//    //check file type
//    if(fileType != ".jack"){
//        std::cout << "Wrong file type. Must be .jack" << std::endl;
//    }
//    //create name for output file
//    output = output + ".xml";
//
//    Tokenizer* tokenizer = new Tokenizer(input_file);
//    tokenizer->closeInputFile();

    return 0;
}
