#include "../Interfaces/ICommandExecutor.h"
#include <iostream>

class DefaultCommandExecutor : public ICommandExecutor {
public:
    bool CanExecute(std::string& command) override {
        return true;
    }

    void Execute(std::string& command) override {
        std::cout << command << ": command not found\n";
    }
};
