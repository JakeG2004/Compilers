#include "errorhandler.h"

std::vector<Error*> ErrorHandler::errors;

void ErrorHandler::AddError(Error::ErrorType errorType, const char* offending, int lineNum)
{
    Error* newError = new Error(errorType, std::string(offending), lineNum);
    newError -> Print();

    errors.push_back(newError);
}

void ErrorHandler::PrintErrors()
{
    for(auto i : errors) {
        i->Print();
    }
}