#include "TokenClass.h"

TokenClass::TokenClass(int tokenClass, int lineNum, char* str, int nValue)
{
    this.tokenClass = class;
    this.lineNum = lineNum;
    this.str = std::string(str);
    this.numVal = GetNumericVal();
}