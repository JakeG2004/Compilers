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
    argDict[arg] = true;
}

void ArgHandler::PrintHelp()
{
    std::cout << "Proper Usage: " << std::endl;
    std::cout << "\t./c- <args> <filename>" << std::endl;
    std::cout << "\tor, cat <filename> | ./c- <args>" << std::endl;
    std::cout << "\tor, ./c- <args> < <filename>" << std::endl;

    std::cout << "\n\tAvailable flags are:" << std::endl;
    std::cout << "\t-p: Prints the AST" << std::endl;
    std::cout << "\t-d: Prints the yydebug info" << std::endl;
    std::cout << "\t?: Brings up this help text" << std::endl;
}