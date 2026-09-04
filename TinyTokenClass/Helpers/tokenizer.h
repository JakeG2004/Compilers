#include <iostream>
#include <vector>

#include "tokenclass.h"

class Tokenizer
{
    public:
        static std::vector<TokenClass*> tokens;

    public:
        static void AddToken(int tokenClass, int lineNo, char* str, int yylval);
};