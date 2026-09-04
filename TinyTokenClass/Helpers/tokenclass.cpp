#include "tokenclass.h"

#include <cstdio>

TokenClass::TokenClass(int tokenClass, int lineNum, char* str, int nValue)
{
    this->tokenClass = tokenClass;
    this->lineNum = lineNum;
    this->str = std::string(str);
    this->numVal = nValue;
}

void TokenClass::Print()
{
    printf("== TOKEN ==\n"
            "Class: %i\n"
            "Line Number: %i\n"
            "String: \"%s\"\n"
            "Value: %i\n\n", tokenClass, lineNum, str.c_str(), numVal);
}