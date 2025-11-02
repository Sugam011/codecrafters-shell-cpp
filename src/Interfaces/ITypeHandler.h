#pragma once
#include <string>

class ITypeHandler {
public:
    virtual bool CanHandle(const std::string& command) const = 0;
    virtual bool Handle(const std::string& command) const = 0;
    virtual ~ITypeHandler() = default;
};