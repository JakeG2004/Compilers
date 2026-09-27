#include <string>

class Error
{
    public:
        enum ErrorType
        {
            LONG_CHAR,
            WARNING,

            // COMPARE ENUM VALUES TO MAKE PRINTING SIMPLER

            ERROR,
            INVALID_CHAR,
            EMPTY_CHAR,
        };

        ErrorType errorType;
        std::string offending;
        int lineNum;
    
    public:
        Error(ErrorType errorType, std::string offending, int lineNum);
        void Print();
};