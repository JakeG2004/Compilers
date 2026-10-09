#include "errorhandler.h"

ErrorHandler::ErrorHandler() {}

void ErrorHandler::AddError(Error::ErrorType errorType, std::string content, int lineNum)
{
    GetInstance()->InstAddError(errorType, content, lineNum);
}

void ErrorHandler::InstAddError(Error::ErrorType errorType, std::string content, int lineNum)
{
    Error* newError = new Error(errorType, content, lineNum);
    errors.push_back(newError);

    if(errorType > Error::ErrorType::ERROR)
        numErrors++;
    if(errorType < Error::ErrorType::WARNING)
        numWarnings++;
}

int ErrorHandler::GetNumErrors()
{
    return GetInstance()->numErrors;
}

int ErrorHandler::GetNumWarnings()
{
    return GetInstance()->numWarnings;
}