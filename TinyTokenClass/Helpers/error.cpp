#include "error.h"

Error::Error(ErrorType errorType, std::string message, int lineNum)
{
    this->errorType = errorType;
    this->message = message;
    this->lineNum = lineNum;
}

void Error::Print()
{
    std::string errorTypeStr;
    switch(errorType) {
        case LEXER:
            errorTypeStr = "Lexer";
            break;
        case PARSER:
            errorTypeStr = "Parser";
            break;
        default:
            errorTypeStr = "Unknown";
            break;
    }
    printf("%s error on line %i: %s\n", errorTypeStr.c_str(), lineNum, message.c_str());
}