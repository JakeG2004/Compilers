#include <vector>
#include "TokenClass.h"

class Tokenizer
{
    public:
        static std::vector<TokenClass*> tokens;
    
    public:
        static void PrintTokens();
        static void CreateAndAddNewToken(char* str, int lineNum, int nValue);
};