#include "CommandSource.hpp"

class AlwayNextTurn : public CommandSource 
{
    int turnsPlayed = 0;

    std::string nextCommand() override;
};
