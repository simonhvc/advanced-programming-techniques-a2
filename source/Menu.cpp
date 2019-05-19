#include "Menu.h"


Menu::Menu(){
    std::cout << "WELCOME TO QWIRKLE!\n-------------------" << std::endl;
    std::cout << "Enter 'help' at any time for a list of commands\n-------------------" << std::endl;  
}

Menu::~Menu(){
    //delete players[0];
    //delete players[1];
    //delete[] players;
}

void Menu::startMenu(){
    printMenu();
    int sel = getMenuSelection();
    executeOption(sel);
}

//-------- Display Menu ---------//
void Menu::printMenu(){
    std::cout << "Menu\n----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Show Student Information" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

//-------- Initial Menu Selection ---------//
int Menu::getMenuSelection(){
    std::string selectionString;
    int selectionInt = 0;
    bool validSelection = false;

    while(!validSelection){         // Loops until a valid choice is made
        selectionString = getInputStr();

        if (std::cin.fail()){
            std::cerr << "Error" << std::endl;
        }

        if((selectionString == "help") || (selectionString == "HELP")){
            std::cout << "Select a menu option from 1-4 and press Enter." << std::endl;
        } 

        else try{
            selectionInt = std::stoi(selectionString); 
            if (selectionInt < 1 || selectionInt > 4) {
                    std::cerr << "Error -- Please enter a valid menu item." << std::endl;
            }
            else{
                validSelection = true;
            }
        }
        catch(...){
            std::cerr << "Error -- Please enter an integer" << std::endl;
        }
        std::cin.clear();           // clear error flag
        std::cin.ignore();
    }
    return selectionInt;
}


//-------- Executing Menu Choice ---------//
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

    else{
        quitGame();
    }
}


//-------- New Game Initialization ---------//
void Menu::newGame(){
    std::cout << "Starting a New Game" << std::endl;
    std::cout << "Player 1, enter your name (uppercase characters only): " << std::endl;
    players[0] = new Player(getPlayerName());
    std::cout << "Player 2, enter your name (uppercase characters only): " << std::endl;
    players[1] = new Player(getPlayerName());
    std::cout << "\nLet's Play!" << std::endl;
    //ToDo GAMEPLAY starts here
}

std::string Menu::getPlayerName(){
    bool validName = false;
    std::string name;

    while(!validName){         // Loops until a valid choice is made
        name = getInputStr();

        if (std::cin.fail()){
            std::cerr << "Error" << std::endl;
        }

        for (unsigned int i = 0; i < name.length(); i++) {
            if ((std::isalpha(static_cast<unsigned char>(name[i])) && std::isupper(static_cast<unsigned char>(name[i])))){
                validName = true;
            }

            else{
                validName = false;
            }  
        }

        if(!validName){
            std::cerr << "Error -- Ensure you only enter uppercase characters" << std::endl;
        }
        std::cin.clear();           // clear error flag
        std::cin.ignore();
    }
    return name;
}


//-------- Load Game ---------//
void Menu::loadGame(){
    std::cout << "Please enter the path to the Save Game file" << std::endl;
    std::ifstream savedGame;
    std::string saveLocation = getInputStr();
    savedGame.open(saveLocation);
    if (savedGame.fail()) {
        std::cout << "Error -- File does not exist or is inaccessible" << std::endl;
    }


}


//-------- Print Team Members ---------//
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


//-------- Quit ---------//
void Menu::quitGame(){
    std::cout << "Goodbye!" << std::endl;
    std::exit(0);
}

//-------- Get a string input (and check for EoF). Error handling is done where this is called ---------//
std::string Menu::getInputStr(){
    std::cout << "> ";      //User Input Prompt

    std::string inputVar;
    
    std::cin >> inputVar;

    if (std::cin.eof()){
        quitGame();         //quit if EoF is entered
    }
    return inputVar;
}
