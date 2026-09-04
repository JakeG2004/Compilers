#include <string>

class Error
{
    public:
        enum ErrorType
        {
            LEXER,
            PARSER,
        };
        ErrorType errorType;
        std::string message;
        int lineNum;
    
    public:
        Error(ErrorType errorType, std::string message, int lineNum);
        void Print();
};