#ifndef ARGHANDLER_H
#define ARGHANDLER_H

#include <unordered_map>
#include <string>

class ArgHandler
{
    public:
        static std::unordered_map<std::string, bool> argDict;

    public:
        static void ProcessArgs(int argc, char* argv[]);
        static bool IsFlagSet(const std::string& flag);
        static void PrintHelp();

    private:
        static void AddArg(const std::string& arg);
};

#endif