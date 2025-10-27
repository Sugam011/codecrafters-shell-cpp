#include <iostream>
#include <string>
#include "Executors/CommandExecutorManager.h"

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
 CommandExecutorManager manager;

    std::string command;
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, command);
        manager.ExecuteCommand(command);
    }
}