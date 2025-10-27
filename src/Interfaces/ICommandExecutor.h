#include<string>

class ICommandExecutor{
    public:
    virtual bool CanExecute(std::string& command) = 0;
    virtual void Execute(std::string& command) = 0;
}