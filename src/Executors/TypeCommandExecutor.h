#pragma once
#include "../Interfaces/ICommandExecutor.h"
#include "../Interfaces/ITypeHandler.h"
#include "../TypeHandlers/BuiltinTypeHandler.h"
#include "../TypeHandlers/ExecutableTypeHandler.h"
#include <vector>
#include <memory>
#include <string>

class TypeCommandExecutor : public ICommandExecutor {
    std::vector<std::unique_ptr<ITypeHandler>> handlers;

public:
    TypeCommandExecutor() {
        handlers.push_back(std::make_unique<BuiltinTypeHandler>());
        handlers.push_back(std::make_unique<ExecutableTypeHandler>());
    }

    bool CanExecute(std::string& command) override {
        return command.rfind("type ", 0) == 0;
    }

    void Execute(std::string& command) override {
        std::string target = command.substr(5);
        for (auto& h : handlers) {
            if (h->CanHandle(target) && h->Handle(target))
                return;
        }
        std::cout << target << ": not found" << std::endl;
    }
};
