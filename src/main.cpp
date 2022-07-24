#include "GameOfLifeModel.hpp"
#include "GameOfLifeView.hpp"
#include "GameOfLifeController.hpp"
#include "AlwaysNextTurn.hpp"
#include "UserCommands.hpp"
#include "Cylinder.hpp"
#include "Torus.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{   
    system("clear");

    if (argc > 1)
    {
        std::cout << "You have entered " << argc << " arguments:" << "\n";
    }
    else
    {
        std::cout << "You have entered " << argc << " argument:" << "\n";
        std::cout << "Choose source of commands as a secon argument [user, auto]" << "\n";
        std::cout << "Bye!" << "\n";
    }

    std::string chooseProcedure;

    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << "\n";

        if (i == 1)
        {
            chooseProcedure = argv[i];
        }
    }

    // std::string chooseTypeOfBoard;
    // std::cout << "Choose type of board [plane, cylinder, torus]: ";
    // std::cin >> chooseTypeOfBoard;

    sleep(5);

    std::fstream plik;

    plik.open("plansza.txt", std::ios::in);

    if (not plik.is_open())
        return 1;

    std::string chooseTypeOfBoard;
    std::getline(plik, chooseTypeOfBoard);

    int width, height;
    plik >> width >> height;

    system("clear");

    if (chooseProcedure == "auto")
    {
        AlwayNextTurn autoCommandSource;
    
        if (chooseTypeOfBoard == "plane")
        {
            GameOfLifeModel board;
            GameOfLifeView view{board};
            GameOfLifeController ctrl{board, view};
            ctrl.chosenProcedure(autoCommandSource);
        }

        if (chooseTypeOfBoard == "cylinder")
        {
            Cylinder cylinder;
            GameOfLifeView view{cylinder};
            GameOfLifeController ctrl{cylinder, view};
            ctrl.chosenProcedure(autoCommandSource);
        }

        if (chooseTypeOfBoard == "torus")
        {
            Torus torus;
            GameOfLifeView view{torus};
            GameOfLifeController ctrl{torus, view};
            ctrl.chosenProcedure(autoCommandSource);
        }
    }
    else if (chooseProcedure == "user")
    {
        UserCommands userCommandSource;

        if (chooseTypeOfBoard == "normal")
        {
            GameOfLifeModel board;
            GameOfLifeView view{board};
            GameOfLifeController ctrl{board, view};
            ctrl.chosenProcedure(userCommandSource);
        }

        if (chooseTypeOfBoard == "cylinder")
        {
            Cylinder cylinder;
            GameOfLifeView view{cylinder};
            GameOfLifeController ctrl{cylinder, view};
            ctrl.chosenProcedure(userCommandSource);
        }

        if (chooseTypeOfBoard == "torus")
        {
            Torus torus;
            GameOfLifeView view{torus};
            GameOfLifeController ctrl{torus, view};
            ctrl.chosenProcedure(userCommandSource);
        }
    }

    plik.close();

    return 0;
}
