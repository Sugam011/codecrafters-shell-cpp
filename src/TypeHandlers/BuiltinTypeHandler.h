    #pragma once
#include "../Interfaces/ITypeHandler.h"
#include "../Executors/BuiltinCommands.h"
#include <iostream>

class BuiltinTypeHandler : public ITypeHandler {
public:
    bool CanHandle(const std::string& command) const override {
        return BuiltinCommands::IsBuiltin(command);
    }

    bool Handle(const std::string& command) const override {
        std::cout << command << " is a shell builtin" << std::endl;
        return true;
    }
};