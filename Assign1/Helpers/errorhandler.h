#include "error.h"

#include <iostream>
#include <vector>
#include <string>

class ErrorHandler
{
    public:
        static std::vector<Error*> errors;
    
    public:
        static void AddError(Error::ErrorType errorType, const char* offending, int lineNum);
        static void PrintErrors();
};