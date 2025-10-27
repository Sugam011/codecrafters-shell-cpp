#pragma once
#include "../Interfaces/ICommandExecutor.h"
#include <cstdlib>

class SuccessExitCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command == "exit 0";
    }

    void Execute(std::string& command) override {
        std::exit(0);
    }
};
