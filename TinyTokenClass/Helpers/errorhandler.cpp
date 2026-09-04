#include "errorhandler.h"

std::vector<Error*> ErrorHandler::lexerErrors;
std::vector<Error*> ErrorHandler::parserErrors;

void ErrorHandler::AddError(Error::ErrorType errorType, const char* message, int lineNum)
{
    Error* newError = new Error(errorType, std::string(message), lineNum);

    std::vector<Error*> errorList;
    switch(errorType)
    {
        case Error::ErrorType::LEXER:
            errorList = lexerErrors;
            break;
        case Error::ErrorType::PARSER:
            errorList = parserErrors;
            break;
        default:
            //errorList = nullptr;
            break;
    }

    errorList.push_back(newError);
}

void ErrorHandler::PrintErrors()
{
    for(auto i : lexerErrors) {
        i->Print();
    }

    for(auto i : parserErrors) {
        i->Print();
    }
}