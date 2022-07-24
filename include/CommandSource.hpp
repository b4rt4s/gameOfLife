#pragma once
#include <string>

class CommandSource
{
public:
    virtual std::string nextCommand() = 0;
    virtual ~CommandSource() {};
};
