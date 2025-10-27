#pragma once
#include "../Interfaces/ICommandExecutor.h"
#include <iostream>

class EchoCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command.rfind("echo ", 0) == 0;
    }

    void Execute(std::string& command) override {
        std::string output = command.substr(5);
        std::cout << output << std::endl;
    }
};
