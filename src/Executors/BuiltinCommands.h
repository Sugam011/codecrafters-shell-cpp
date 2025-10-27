#pragma once
#include <string>
#include <vector>
#include <algorithm>

class BuiltinCommands {
public:
    static bool IsBuiltin(const std::string& command) {
        static const std::vector<std::string> builtins =
         {
            "echo",
             "exit",
             "type"
         };
        return std::find(builtins.begin(), builtins.end(), command) != builtins.end();
    }
};
