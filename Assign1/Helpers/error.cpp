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

    switch(errorType) {
        case INVALID_CHAR:
            std::cout << "Invalid or misplaced input character: '" << offending << "'. Character Ignored." << std::endl; 
            break;

        case LONG_CHAR:
            std::cout << "character is " << offending.length() - 2 << " characters long and not a single character: '" << offending << "'.  The first char will be used." << std::endl;
            break;

        case EMPTY_CHAR:
            std::cout << "Empty character " << offending << ".  Characters ignored." << std::endl;
            break;
    }
}