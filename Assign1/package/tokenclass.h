#include <string>

class TokenClass
{
    public:
        int tokenClass;
        int lineNum;
        std::string tokenStr;
        std::string tokenName;
        char charValue;
        long long int numVal;
        std::string stringVal;

    public:
        TokenClass(int tokenClass, int lineNum, char* str, char cValue, long long int nValue);
        void Print();

    private:
        void GetTokenStringFromId();
        void GetStringValue();
};