#include "Executors/CommandExecutorManager.h"
#include <iostream>

int main() {
    CommandExecutorManager manager;
    std::string command;

    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, command);
        manager.ExecuteCommand(command);
    }

    return 0;
}
