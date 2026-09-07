#include "tokenizer.h"

std::vector<TokenClass*> Tokenizer::tokens;

void Tokenizer::AddToken(int tokenClass, int lineNo, char* str, char cValue, long long int yylval)
{
    TokenClass* newToken = new TokenClass(tokenClass, lineNo, str, cValue, yylval);
    newToken -> Print();

    tokens.push_back(newToken);
}

void Tokenizer::PrintTokens()
{
    for(auto i : tokens) {
        i -> Print();
    }
}