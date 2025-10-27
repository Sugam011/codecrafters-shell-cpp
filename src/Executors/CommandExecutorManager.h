#pragma once
#include "../Interfaces/ICommandExecutor.h"
#include "SuccessExitCommandExecutor.h"
#include "ExitCommandExecutor.h"
#include "DefaultCommandExecutor.h"
#include "EchoCommandExecutor.h"

#include <vector>
#include <memory>
#include <iostream>
#include <string>

class CommandExecutorManager {
private:
    std::vector<std::unique_ptr<ICommandExecutor>> executors;

public:
    CommandExecutorManager() {
        executors.push_back(std::make_unique<SuccessExitCommandExecutor>());
        executors.push_back(std::make_unique<ExitCommandExecutor>());
        executors.push_back(std::make_unique<EchoCommandExecutor>());
        executors.push_back(std::make_unique<DefaultCommandExecutor>());
    }

    void ExecuteCommand(std::string command) {
        for (auto& executor : executors) {
            if (executor->CanExecute(command)) {
                executor->Execute(command);
                return;
            }
        }
        std::cout << "Unknown command: " << command << std::endl;
    }
};
