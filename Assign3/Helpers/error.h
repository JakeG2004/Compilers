#ifndef ERROR_H
#define ERROR_H
#include <string>

class Error
{
    public:
        enum ErrorType
        {
            WARNING,
            ERROR,
        };

        ErrorType errorType;
        std::string offending;
        int lineNum;
    
    public:
        Error(ErrorType errorType, std::string offending, int lineNum);
        void Print();
};
#endif