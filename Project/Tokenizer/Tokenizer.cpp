#include <iostream>
#include "Tokenizer.h"

void Tokenizer::CreateAndAddNewToken(char* str, int lineNum, int nValue)
{
    TokenClass* newToken = new TokenClass(0, lineNum, str, nValue);
    Tokenizer::tokens.push_back(newToken);
}

void Tokenizer::PrintTokens()
{
    std::cout << "Test" << std::endl;
}