#include "error.h"

#include <iostream>
#include <vector>
#include <string>

class ErrorHandler
{
    public:
        static std::vector<Error*> lexerErrors;
        static std::vector<Error*> parserErrors;
    
    public:
        static void AddError(Error::ErrorType errorType, const char* message, int lineNum);
        static void PrintErrors();
};