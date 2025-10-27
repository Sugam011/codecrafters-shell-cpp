#include "../Interfaces/ICommandExecutor.h"
#include <iostream>

class SuccessExitCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command == "exit 0";
    }

    void Execute(std::string& command) override {
        exit(0);
    }
};
