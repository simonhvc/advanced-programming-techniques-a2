#include <iostream>
#include "Menu.h"

    Menu::Menu(){
        std::cout << "WELCOME TO QWIRKLE!\n-------------------" << std::endl;
    }

    void Menu::printMenu(){
        std::cout << "Menu\n----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Show Student Information" << std::endl;
        std::cout << "4. Quit" << std::endl;
    }

    int Menu::getSelection(){
        int selection = 0;
        bool validSelection = false;

        while(!validSelection){
            std::cin >> selection;

            if (std::cin.fail()){
                std::cerr << "Error -- Please enter an integer." << std::endl;
            }

            if (selection < 1 || selection > 4) {
                std::cerr << "Error -- Please enter a valid menu item." << std::endl;
            }
            else{
                validSelection = true;
            }

            std::cin.clear();
            std::cin.ignore();
        }

        return selection;
    }

    void Menu::executeOption(int selection){
        if (selection == 1){
            newGame();
        }

        else if (selection == 2){
            loadGame();
        }

        else if (selection == 3){
            showStudents();
        }

        else if (selection == 4){
            quit();
        }

        else{
            // error handling
        }
    }

    void Menu::newGame(){
        //todo
        std::cout << "Executing  New Game" << std::endl;
    }

    void Menu::loadGame(){
        //todo
        std::cout << "Executing  Load Game" << std::endl;
    }

    void Menu::showStudents(){
        //todo
        std::cout << "Executing  Show Students" << std::endl;
    }

    void Menu::quit(){
        //todo
        std::cout << "Executing  Quit" << std::endl;
    }