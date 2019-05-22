#include "Menu.h"



Menu::Menu(){
    std::cout << "WELCOME TO QWIRKLE!\n-------------------" << std::endl;
    std::cout << "Enter 'help' at any time for a list of commands\n-------------------" << std::endl;
}

Menu::~Menu(){
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
    numPlayers = 0;
    boardSize = 0;

    while (numPlayers == 0) {
      try {
        numPlayers = std::stoi(getInputStr());
      }
    catch (...) {
      numPlayers = 0;
      }
    }

    std::cout << "Enter Board Size" << '\n';

    while (boardSize == 0) {
      try {
        boardSize = std::stoi(getInputStr());
      }
    catch (...) {
      boardSize = 0;
      }
    }

    for(int i = 0; i < numPlayers; i++) {
      std::cout << "Player " << i + 1 << ", enter your name (uppercase characters only): " << std::endl;
      players[i] = new Player(getPlayerName());
    }

    std::cout << "\nLet's Play!" << std::endl;

    //Initalizes the bag and board
    this->bag = new Bag();
    this->board = new Board(boardSize,boardSize);
    this->bag->fillBag();

    //Places the first tile
    board->firstTile(bag->getTile());

    //Players draw the first tile
    for(int i = 0; i < numPlayers; i++) {
        players[i]->Draw(bag, 5);
    }

    gameplayLoop();
}

void Menu::gameplayLoop() {
  bool loop = true;
  //The gameplay loop
  while(loop) {

    std::string response = "";
    bool hasPlacedTile = false;
    Tile* tileToPlace = nullptr;
    int yPos = 0;
    int xPos = 0;
    int score = 0;

    for(int i = 0; i < 2; i++) {


      //Gets the player command
      while (response != "place" && response != "replace") {
        std::cout << players[i]->getName() << "'s turn" << '\n';
        std::cout << "Score for " << players[i]->getName() << ": " << players[i]->getScore() << '\n';
        std::cout << "Your hand is:" << '\n';
        std::cout << players[i]->handToString() << '\n';
        std::cout << board->toString() << '\n';

        response = getInputStr();
        std::cout << response << '\n';
      }

      //Prompts the player to select the tile he wants to replace
      if (response == "replace") {
        Tile* tiletoReplace = NULL;
        while (tiletoReplace == nullptr) {
          std::cout << "Chose tile to replace..." << '\n';
          response = getInputStr();

          if (response.size() == 2) {
            char color = response.at(0);
            int shape = response.at(1) - '0';
            //Checks if the player has the tile he wants to replace
            tiletoReplace = players[i]->hasTile(color, shape);
          }

        }

        //Deletes the tile he wants to replace
        players[i]->deleteTile(tiletoReplace->getColour(), tiletoReplace->getShape());
        //draws a new tile
        players[i]->Draw(bag, 1);
        hasPlacedTile = true;
      }

      //Prompts the player to chose which tile to place
      while (tileToPlace == nullptr && !hasPlacedTile) {
        std::cout << "Chose tile to place..." << '\n';
        response = getInputStr();

        if (response.size() == 2) {
          char color = response.at(0);
          int shape = response.at(1) - '0';

          //Validates that the player has the tile
          tileToPlace = players[i]->hasTile(color, shape);
          //Deletes the tile after use
          players[i]->deleteTile(tileToPlace->getColour(), tileToPlace->getShape());
          //Draws a new tile
          players[i]->Draw(bag, 1);
        }

      }

      while (!hasPlacedTile) {

        //Prompts the player to give the position he wants to place the tile on
        std::cout << "Chose position..." << '\n';
        response = getInputStr();

        if (response.size() == 2) {
          //Gets the tile position
          yPos = board->getIndexOfChar(response.at(0));
          xPos = response.at(1) - '0';
          std::cout << "placing tile..." << '\n';
          score = board->placeTile(xPos - 1, yPos, tileToPlace);
          std::cout << "done placing tile" << '\n';
        }

        //Gives score if placement is valid
        if (score != -1) {
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
    std::vector<std::vector<std::string>> playerHands;

    for (int i = 0; i < 2; i++){
        /* Loading Names */
        std::string playerName = "";
        std::getline(savedGame, playerName, '\n');
        playerName = deleteReturnChar(playerName);
        for (unsigned int i = 0; i < playerName.length(); i++) {
            if (!std::isalpha(static_cast<unsigned char>(playerName[i])) || !std::isupper(static_cast<unsigned char>(playerName[i]))){
                validFormat = false;
            }
        }
        /* Loading Scores */
        std::string playerScore = "";
        std::getline(savedGame, playerScore);
        playerScore = deleteReturnChar(playerScore);
        for (unsigned int i = 0; i < playerScore.length(); i++) {
            if (!std::isdigit(playerScore[i])){
                validFormat = false;
            }
        }
        /* Loading Hands */
        std::string playerHandLine = "";
        std::getline(savedGame, playerHandLine, '\n');
        playerHandLine = deleteReturnChar(playerHandLine);
        std::stringstream handStream(playerHandLine);
        std::string tile = "";
        std::vector<std::string> tileVector;
        while(getline(handStream, tile,','))
        {
            if (!(tile.length() == 2) || !(tile[0] == 'R' || tile[0] == 'O' || tile[0] == 'Y' || tile[0] == 'G' || tile[0] == 'B' || tile[0] == 'P') || !(tile[1] == '1' || tile[1] == '2' || tile[1] == '3' || tile[1] == '4' || tile[1] == '5' || tile[1] == '6')){
                validFormat = false;
            }
            else{
                tileVector.push_back(tile);
            }
        }

        if(validFormat){
            playerNames[i] = playerName;
            playerScores[i] = std::stoi(playerScore);
            playerHands.push_back(tileVector);
        }
    }

        /* Loading Board */

        /* Loading Bag */
        std::string bagLine = "";
        std::getline(savedGame, bagLine, '\n');
        bagLine = deleteReturnChar(bagLine);
        std::stringstream bagStream(bagLine);
        std::string tile = "";
        char color = 0;
        int shape = 0;
        std::vector<Tile*> bagVector;
        while(getline(bagStream, tile,','))
        {
            if (!(tile.length() == 2) || !(tile[0] == 'R' || tile[0] == 'O' || tile[0] == 'Y' || tile[0] == 'G' || tile[0] == 'B' || tile[0] == 'P') || !(tile[1] == '1' || tile[1] == '2' || tile[1] == '3' || tile[1] == '4' || tile[1] == '5' || tile[1] == '6')){
                validFormat = false;
            }
            else{
                color = tile.at(0);
                shape = tile.at(1) - '0';
                bagVector.push_back(new Tile(color, shape));
            }
        }

        /* Loading Current Player */
        std::string currentPlayer = "";
        std::getline(savedGame, currentPlayer, '\n');
        currentPlayer = deleteReturnChar(currentPlayer);

    if (validFormat && savedGame.good()){
        //validation success, set all the variable and start the game
        //for now I am just outputting them
        for (int i = 0; i < 2; i++){
            std::cout << playerNames[i] << std::endl;
            std::cout << playerScores[i] << std::endl;
            for (unsigned int j = 0; j < playerHands[i].size(); j++){
                std::cout << playerHands[i][j] << std::endl;
            }
        }

        /* Set the Current Player */
        std::string temp = "";
        for (int i = 0; i < 2; i++){
            if (this->players[i]->getName() == currentPlayer){
                temp = this->players[0]->getName();
                this->players[i]->setName(temp);
                this->players[0]->setName(currentPlayer);
            }
        }

        //Board* board = new Board(boardSize,boardSize);

        this->bag = new Bag();
        //this->bag->fillBag();
        for (unsigned int i = 0; i < bagVector.size(); i++){
            this->bag->addToBag(bagVector[i]);
        }
        //Board* board = new Board(boardSize,boardSize);
        //Loop to populate board
    }
    savedGame.clear();
    savedGame.close();
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
