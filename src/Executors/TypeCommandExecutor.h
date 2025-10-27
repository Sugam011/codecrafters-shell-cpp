#pragma once
#include "../Interfaces/ICommandExecutor.h"
#include "BuiltinCommands.h"
#include <iostream>
#include <string>

class TypeCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        std::string target = command.substr(5);
        return
         command.rfind("type ", 0) == 0 &&
         BuiltinCommands::IsBuiltin(target);
    }

    void Execute(std::string& command) override {
        std::string target = command.substr(5);
         std::cout << target << " is a shell builtin" << std::endl;
    }
};
