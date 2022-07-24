// #pragma once
#include "CommandSource.hpp"

class UserCommands : public CommandSource 
{
    std::string getCommand();
    std::string nextCommand() override;

// public:
//     int getRow();
//     int getCol();
};
