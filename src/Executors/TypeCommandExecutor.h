#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>      // for access()
#include <dirent.h>      // for opendir(), readdir()
#include "../Interfaces/ICommandExecutor.h"
#include "BuiltinCommands.h"

class TypeCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command.rfind("type", 0) == 0; // starts with "type"
    }

    void Execute(std::string& command) override {
        std::string target = command.substr(5); // text after "type "
        if (target.empty()) {
            std::cout << "Usage: type <command>" << std::endl;
            return;
        }

        // Trim leading/trailing spaces
        target.erase(0, target.find_first_not_of(" \t"));
        target.erase(target.find_last_not_of(" \t") + 1);

        // 1️⃣ Check if it's a builtin
        if (BuiltinCommands::IsBuiltin(target)) {
            std::cout << target << " is a shell builtin" << std::endl;
            return;
        }

        // 2️⃣ Search in PATH
        char* pathEnv = getenv("PATH");
        if (!pathEnv) {
            std::cout << target << ": not found" << std::endl;
            return;
        }

        std::string pathStr(pathEnv);
        std::vector<std::string> paths = SplitPath(pathStr);

        for (const auto& dir : paths) {
            std::string fullPath = dir + "/" + target;

            // Check if the file exists and is executable
            if (access(fullPath.c_str(), X_OK) == 0) {
                std::cout << target << " is " << fullPath << std::endl;
                return;
            }
        }

        std::cout << target << ": not found" << std::endl;
    }

private:
    // Split PATH using ':' (or ';' on Windows)
    std::vector<std::string> SplitPath(const std::string& pathStr) {
#ifdef _WIN32
        char delimiter = ';';
#else
        char delimiter = ':';
#endif
        std::vector<std::string> result;
        std::stringstream ss(pathStr);
        std::string item;

        while (std::getline(ss, item, delimiter)) {
            if (!item.empty())
                result.push_back(item);
        }
        return result;
    }
};
