#include "../Interfaces/ICommandExecutor.h"
#include <iostream>

class ExitCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return command == "exit 1";
    }

    void Execute(std::string& command) override {
        exit(1);
    }
};
