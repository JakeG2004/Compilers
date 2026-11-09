#include "error.h"
#include <iostream>

Error::Error(ErrorType errorType, std::string content, int lineNum)
{
    this->errorType = errorType;
    this->content = content;
    this->lineNum = lineNum;
}

void Error::Print()
{
    std::string lineStr = std::to_string(lineNum);
    if(lineNum == 0) {
        lineStr = std::string("LINKER");
    }

    if(errorType == ERROR)
        std::cout << "ERROR(" << lineStr << "): ";
    if(errorType == WARNING)
        std::cout << "WARNING(" << lineStr << "): ";

    std::cout << content << std::endl;
}