#include <string>

class TokenClass
{
    public:
        int tokenClass;
        int lineNum;
        std::string str;
        int numVal;

    public:
        TokenClass(int tokenClass, int lineNum, char* str, int nValue);
        void Print();
};