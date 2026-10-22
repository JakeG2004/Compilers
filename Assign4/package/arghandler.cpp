#include "arghandler.h"
#include <iostream>

std::unordered_map<std::string, bool> ArgHandler::argDict;

void ArgHandler::ProcessArgs(int argc, char* argv[])
{
    for(int i = 0; i < argc; i++) {
        AddArg(argv[i]);
    }
}

bool ArgHandler::IsFlagSet(const std::string& flag)
{
    auto it = argDict.find(flag);
    if(it == argDict.end())
        return false;

    return it->second;
}

void ArgHandler::AddArg(const std::string& arg)
{
    argDict.insert({arg, true});
}

void ArgHandler::PrintHelp()
{
    std::cout << "Usage: c- [options] [sourceFile]" << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "-d - turn on parser debugging" << std::endl;
    std::cout << "-D - turn on symbol table debugging" << std::endl;
    std::cout << "-h - this usage message" << std::endl;
    std::cout << "-p - print the abstract syntax tree" << std::endl;
    std::cout << "-P - print the abstract syntax tree plus type information" << std::endl;
}