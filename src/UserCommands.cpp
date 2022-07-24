#include "UserCommands.hpp"
#include <chrono>
#include <thread>
#include <iostream>

std::string UserCommands::getCommand()
{
    std::string chooseCommand;
    std::cout << "\nChoose command [next, quit, *toggle - currently not working]: ";
    std::cin >> chooseCommand;

    return chooseCommand;
}

// int UserCommands::getRow()
// {
//     int row;
//     std::cout << "Choose row from 0 to 9: ";
//     std::cin >> row;

//     return row;
// }

// int UserCommands::getCol()
// {
//     int col;
//     std::cout << "Choose col from 0 to 9: ";
//     std::cin >> col;

//     return col;
// }

std::string UserCommands::nextCommand()
{
    using namespace std::chrono_literals;
    
    std::this_thread::sleep_for(200ms);

    std::string command = getCommand();

    if (command == "next")
    {
        return "next";
    }
    
    return "quit";

    // return "toggle";
}