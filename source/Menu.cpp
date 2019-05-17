#include <iostream>
#include "Menu.h"


    Menu::Menu(){
        std::cout << "WELCOME TO QWIRKLE!\n-------------------" << std::endl;
    }

    void Menu::startMenu(){
        printMenu();
        int sel = getSelection();
        executeOption(sel);
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
            promptUser();
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
        std::cout << "Starting a New Game" << std::endl;
        std::string player1, player2;
        std::cout << "Player 1, enter your name (uppercase only): " << std::endl;
        std::cin >> player1;
        players[0] = new Player(player1);
        std::cout << "Player 2, enter your name (uppercase only): " << std::endl;
        std::cin >> player2;
        players[1] = new Player(player2);
    }

    void Menu::loadGame(){
        //todo
        std::cout << "Executing  Load Game" << std::endl;
    }

    void Menu::showStudents(){
        std::cout << "-------------------\n" << std::endl;
        for(int i = 0; i < 3; i++){
            std::cout << "Name: " << this->students[i][0] <<std::endl;
            std::cout << "Student ID: " << this->students[i][1]<< std::endl;
            std::cout << "Email: "<< this->students[i][2] << "\n" << std::endl;
        }

        std::cout << "-------------------\n Press enter to return to Menu..." << std::endl;
        std::cin.ignore(100, '\n');
        startMenu();
    }

    void Menu::quit(){
        //todo -- memory management atexit()
        std::cout << "Goodbye!" << std::endl;
        exit(0);
    }

    void Menu::promptUser(){
        std::cout << "> ";
    }