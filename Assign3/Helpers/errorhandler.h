#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "error.h"
#include "tokenclass.h"

#include <iostream>
#include <vector>
#include <string>

class ErrorHandler
{
    public:
        static ErrorHandler* GetInstance()
        {
            static ErrorHandler obj;
            return &obj;
        }
        static int GetNumErrors();
        static int GetNumWarnings();

    public:
        static void AddAddError(Error::ErrorType errorType, std::string content, int lineNum);
        static void AddVarCallError(TokenClass* token);
        static void AddFunVarError(TokenClass* token);
        static void AddBothOpArrError(TokenClass* token);
        static void AddLHSOpError(TokenClass* token);
        static void AddRHSOpError(TokenClass* token);
        static void AddBothOpTypeError(TokenClass* token);
        static void AddUnaryOpError(TokenClass* token);
        static void AddRetArrError(TokenClass* token);
        static void AddReDeclError(TokenClass* token);
        static void AddUnDeclError(TokenClass* token);
        static void AddArrIdxTypeError(TokenClass* token);
        static void AddIdxWithArrError(TokenClass* token);
        static void AddIdxNonArrError(TokenClass* token);
        static void AddNonArrOpError(TokenClass* token);
        static void AddOnlyArrOpError(TokenClass* token);
    
    public:
        static void AddUnusedVarWarn(TokenClass* token);
        static void AddUninitVarWarn(TokenClass* token);

    public:
        static void AddNoMainError(TokenClass* token);

    protected:
        void InstAddError(Error::ErrorType errorType, std::string content, int lineNum);

    protected:
        std::vector<Error*> errors;
        int numWarnings = 0;
        int numErrors = 0;

    private:
        ErrorHandler();
};

#endif