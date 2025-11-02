    #pragma once
#include "../Interfaces/ITypeHandler.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>

class ExecutableTypeHandler : public ITypeHandler {
public:
    bool CanHandle(const std::string& command) const override {
        return true; // fallback handler
    }

    bool Handle(const std::string& command) const override {
        char* pathEnv = getenv("PATH");
        if (!pathEnv) {
            std::cout << command << ": not found" << std::endl;
            return true;
        }

        std::string path(pathEnv);
        std::vector<std::string> dirs = SplitPath(path);

        for (auto& dir : dirs) {
            std::string fullPath = dir + "/" + command;
            if (access(fullPath.c_str(), X_OK) == 0) {
                std::cout << command << " is " << fullPath << std::endl;
                return true;
            }
        }

        std::cout << command << ": not found" << std::endl;
        return true;
    }

private:
    std::vector<std::string> SplitPath(const std::string& path) const {
        std::vector<std::string> result;
        std::stringstream ss(path);
        std::string dir;
        while (std::getline(ss, dir, ':')) {
            result.push_back(dir);
        }
        return result;
    }
};