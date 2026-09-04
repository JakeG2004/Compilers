#include "tokenizer.h"

std::vector<TokenClass*> Tokenizer::tokens;

void Tokenizer::AddToken(int tokenClass, int lineNo, char* str, int yylval)
{
    TokenClass* newToken = new TokenClass(tokenClass, lineNo, str, yylval);
    newToken->Print();

    tokens.push_back(newToken);
}