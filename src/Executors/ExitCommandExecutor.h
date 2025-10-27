#pragma once
#include "../Interfaces/ICommandExecutor.h"
#include <cstdlib>

class ExitCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command == "exit 1";
    }

    void Execute(std::string& command) override {
        std::exit(1);
    }
};
