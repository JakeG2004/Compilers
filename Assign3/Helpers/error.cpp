#include "error.h"
#include <iostream>

Error::Error(ErrorType errorType, std::string offending, int lineNum)
{
    this->errorType = errorType;
    this->offending = offending;
    this->lineNum = lineNum;
}

void Error::Print()
{
    if(errorType >= ERROR)
        std::cout << "ERROR(" << lineNum << "): ";
    if(errorType <= WARNING)
        std::cout << "WARNING(" << lineNum << "): ";

    std::cout << offending << std::endl;
}