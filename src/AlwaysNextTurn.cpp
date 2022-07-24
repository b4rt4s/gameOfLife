#include "AlwaysNextTurn.hpp"
#include <chrono>
#include <thread>

std::string AlwayNextTurn::nextCommand() 
{
    using namespace std::chrono_literals;
    
    std::this_thread::sleep_for(200ms);

    if (++turnsPlayed > 49)
    {
        return "quit";
    }

    return "next";
}
