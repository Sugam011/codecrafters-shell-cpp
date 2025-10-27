#pragma once
#include "ICommandExecutor.h"
#include "BuiltinCommands.h"
#include <iostream>
#include <string>

class TypeCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command.rfind("type ", 0) == 0; // starts with "type "
    }

    void Execute(std::string& command) override {
        std::string target = command.substr(5); // remove "type "
        if (BuiltinCommands::IsBuiltin(target)) {
            std::cout << target << " is a shell builtin" << std::endl;
        } else {
            std::cout << target << ": not found" << std::endl;
        }
    }
};
