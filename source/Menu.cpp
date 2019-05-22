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
    std::string selectionString = "";
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

    std::cout << "Enter Player Amount" << '\n';
    numPlayers = std::stoi(getInputStr());

    std::cout << "Enter Board Size" << '\n';
    boardSize = std::stoi(getInputStr());

    for(int i = 0; i < numPlayers; i++) {
      std::cout << "Player " << i + 1 << ", enter your name (uppercase characters only): " << std::endl;
      players[i] = new Player(getPlayerName(),0);
    }

    std::cout << "\nLet's Play!" << std::endl;
    this->bag = new Bag();
    this->board = new Board(boardSize,boardSize);
    board->firstTile(bag->getTile());
    players[0]->Draw(bag, 5);
    players[1]->Draw(bag, 5);
    gameplayLoop();
}
//THE MAIN GAMEPLAY LOOP//
void Menu::gameplayLoop() {
  bool loop = true;

  //INitalizes the bag and board
  Bag* bag = new Bag();
  Board* board = new Board(boardSize,boardSize);
  //Places the first tile
  board->firstTile(bag->getTile());

  //Players draw the first tile
  for(int i = 0; i < numPlayers; i++) {
    players[i]->Draw(bag, 5);
  }

  while(loop) {

    std::string response = "";

    for(int i = 0; i < numPlayers; i++) {
      bool hasPlacedTile = false;
      Tile* tileToPlace = nullptr;
      int yPos;
      int xPos;
      int score = 0;

      while (response != "place") {
        std::cout << players[i]->getName() << "'s turn" << '\n';
        std::cout << "SCORE: " << players[i]->getScore() << '\n';
        std::cout << "Hand: " << players[i]->handToString() << '\n';
        std::cout << board->toString() << '\n';
        response = getInputStr();
        std::cout << response << '\n';
      }

      if (response == "replace") {
        Tile* tiletoReplace = NULL;
        while (tiletoReplace == nullptr) {
          std::cout << "Chose tile to replace..." << '\n';
          response = getInputStr();

          if (response.size() == 2) {
            char color = response.at(0);
            int shape = response.at(1) - '0';
            tiletoReplace = players[i]->hasTile(color, shape);
          }

        }

        players[i]->deleteTile(tiletoReplace->getColour(), tileToPlace->getShape());
        players[i]->Draw(bag, 1);

        hasPlacedTile = true;
      }

      while (tileToPlace == nullptr && !hasPlacedTile) {
        std::cout << "Chose tile to place..." << '\n';
        response = getInputStr();

        if (response.size() == 2) {
          char color = response.at(0);
          int shape = response.at(1) - '0';

          tileToPlace = players[i]->hasTile(color, shape);
        }

      }

      while (!hasPlacedTile) {

        std::cout << "Chose position..." << '\n';
        response = getInputStr();

        if (response.size() == 2) {
          yPos = board->getIndexOfChar(response.at(0));
          xPos = response.at(1) - '0';
          std::cout << "placing tile..." << '\n';
          score = board->placeTile(xPos - 1, yPos, tileToPlace);
          std::cout << "done placing tile" << '\n';
        }

        if (score != 0) {
          hasPlacedTile = true;
          players[i]->updateScore(score);
        }
      }
    }
  }
}

std::string Menu::getPlayerName(){
    bool validName = false;
    std::string name = "";

    while(!validName){         // Loops until a valid choice is made
        name = getInputStr();

        if (std::cin.fail()){
            std::cerr << "Error" << std::endl;
        }

        for (unsigned int i = 0; i < name.length(); i++) {
            if (std::isalpha(static_cast<unsigned char>(name[i])) && std::isupper(static_cast<unsigned char>(name[i]))){
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
    bool validFormat = true;
    std::cout << "Please enter the path to the Save Game file" << std::endl;
    std::ifstream savedGame;
    std::string saveLocation = getInputStr();
    savedGame.open(saveLocation);

    if (savedGame.fail()) {
        std::cerr << "Error -- File does not exist or is inaccessible" << std::endl;
    }
    savedGame.clear();


    std::string playerNames[] = {"",""};
    int playerScores[] = {0,0};
    std::vector<std::vector<Tile*>> playerHands;

    for (int i = 0; i < 2; i++){
        std::string playerName = "";
        std::getline(savedGame, playerName, '\n');
        playerName = deleteReturnChar(playerName);
        for (unsigned int i = 0; i < playerName.length(); i++) {
            if (!std::isalpha(static_cast<unsigned char>(playerName[i])) || !std::isupper(static_cast<unsigned char>(playerName[i]))){
                validFormat = false;
            }
        }

        std::string playerScore = "";
        std::getline(savedGame, playerScore);
        playerScore = deleteReturnChar(playerScore);
        for (unsigned int i = 0; i < playerScore.length(); i++) {
            if (!std::isdigit(playerScore[i])){
                validFormat = false;
            }
        }

        std::string playerHandLine = "";
        std::getline(savedGame, playerHandLine, '\n');
        playerHandLine = deleteReturnChar(playerHandLine);
        std::stringstream handStream(playerHandLine);
        std::string tile = "";
        char color = 0;
        int shape = 0;
        std::vector<Tile*> tileVector;
        while(getline(handStream, tile,','))
        {
            if (!(tile.length() == 2) || !(tile[0] == 'R' || tile[0] == 'O' || tile[0] == 'Y' || tile[0] == 'G' || tile[0] == 'B' || tile[0] == 'P') || !(tile[1] == '1' || tile[1] == '2' || tile[1] == '3' || tile[1] == '4' || tile[1] == '5' || tile[1] == '6')){
                validFormat = false;
            }
            else{
                color = tile.at(0);
                shape = tile.at(1) - '0';
                tileVector.push_back(new Tile(color, shape));
            }
        }

        if(validFormat){
            playerNames[i] = playerName;
            playerScores[i] = std::stoi(playerScore);
            playerHands.push_back(tileVector);
        }
    }

    if (validFormat && savedGame.good()){
        //validation success, set all the variable and start the game
        //for now I am just outputting them
        for (int i = 0; i < 2; i++){
            this->players[i] = new Player(playerNames[i], playerScores[i]);
            for (unsigned int j = 0; j < playerHands[i].size(); j++){
                this->players[i]->addToHand(playerHands[i][j]);
            }
        }
        this->bag = new Bag();
        //Board* board = new Board(boardSize,boardSize);
        //Loop to populate board
    }
    this->board = new Board(8,8);
    board->firstTile(bag->getTile());
    savedGame.clear();
    savedGame.close();
    gameplayLoop();
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

    std::string inputVar = "";

    std::cin >> inputVar;

    if (std::cin.eof()){
        quitGame();         //quit if EoF is entered
    }
    return inputVar;
}

std::string Menu::deleteReturnChar(std::string string){

   std::string returnString = "";

   for(unsigned int i=0; i<string.length(); i++){
      if(string[i] != '\r'){
         returnString += string[i];
      }
   }
   return returnString;
}
