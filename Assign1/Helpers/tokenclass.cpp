#include "tokenclass.h"
#include "parser.tab.h"

#include <cstdio>
#include <cctype>
#include <bits/stdc++.h>

#define TOKENSTRING(t) { case t: tokenName=#t; break; }

TokenClass::TokenClass(int tokenClass, int lineNum, char* tokenStr, char cValue, long long int nValue)
{
    this->tokenClass = tokenClass;
    this->lineNum = lineNum;
    this->tokenStr = std::string(tokenStr);
    this->charValue = cValue;
    this->numVal = nValue;

    GetStringValue();
    GetTokenStringFromId();
}

void TokenClass::Print()
{
    std::cout << "Line " << lineNum << " Token: " << tokenName;

    switch(tokenClass) {
        case ID:
            std::cout << " Value: " << stringVal;
            break;

        case NUMCONST:
            std::cout << " Value: " << numVal << "  Input: " << tokenStr;
            break;

        case CHARCONST:
            std::cout << " Value: '" << charValue << "'  Input: " << tokenStr;
            break;

        case STRINGCONST:
            std::cout << " Value: " << stringVal << "  Input: " << tokenStr;
            break;

        case BOOLCONST:
            std::cout << " Value: " << numVal << "  Input: " << tokenStr;
            break;
    }

    std::cout << std::endl;
}

void TokenClass::GetTokenStringFromId()
{
    switch(tokenClass) {
        TOKENSTRING(ID)
        TOKENSTRING(NUMCONST)
        TOKENSTRING(CHARCONST)
        TOKENSTRING(STRINGCONST)
        TOKENSTRING(BOOLCONST)
        TOKENSTRING(EQ)
        TOKENSTRING(NEQ)
        TOKENSTRING(ADDASS)
        TOKENSTRING(SUBASS)
        TOKENSTRING(MULASS)
        TOKENSTRING(DIVASS)
        TOKENSTRING(LEQ)
        TOKENSTRING(GEQ)
        TOKENSTRING(DEC)
        TOKENSTRING(INC)

        default:
            for(int i =0; i < tokenStr.length(); i++) {
                tokenName += toupper(tokenStr[i]);
            }
            break;
    }
}

void TokenClass::GetStringValue()
{
    std::string newStrVal;

    for (int i = 0; i < (int)tokenStr.length(); i++) {
        if (tokenStr[i] == '\\' && i + 1 < tokenStr.length()) {
            switch (tokenStr[i + 1]) {
                case '0':  newStrVal += '\0'; break;
                case 'n':  newStrVal += '\n'; break;
                case 't':  newStrVal += '\t'; break;
                case '\\': newStrVal += '\\'; break;
                case '"':  newStrVal += '"';  break;
                default:   newStrVal += tokenStr[i + 1]; break;
            }
            i++;
        } else {
            newStrVal += tokenStr[i];
        }
    }

    this->stringVal = newStrVal;
}