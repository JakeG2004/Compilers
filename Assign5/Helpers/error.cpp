#include "error.h"
#include <iostream>

Error::Error(ErrorType errorType, std::string content, int lineNum)
{
    this->errorType = errorType;
    this->content = content;
    this->lineNum = lineNum;
}

void Error::Print()
{
    std::string lineStr = std::to_string(lineNum);
    if(lineNum == 0) {
        lineStr = std::string("LINKER");
    }

    std::string line;
    if(errorType == ERROR)
        line = "ERROR(" + lineStr + "): ";
    if(errorType == WARNING)
        line = "WARNING(" + lineStr + "): ";
    line += content;

    // The reference compiler formats each message into a fixed-size buffer,
    // so anything past 110 characters is cut off.
    //const size_t MAX_LINE = 110;
    //if(line.length() > MAX_LINE)
    //    line.resize(MAX_LINE);

    // A cut that leaves trailing blanks is trimmed, as in the expected outputs.
    while(!line.empty() && line.back() == ' ')
        line.pop_back();

    std::cout << line << std::endl;
}