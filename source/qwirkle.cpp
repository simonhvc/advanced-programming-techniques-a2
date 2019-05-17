
#include "Menu.h"
#include "LinkedList.h"
#include "Board.h"
#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   std::cout << "TODO: Implement Qwirkle!" << std::endl;
   //Player* players[20];
   //players[0] = new Player("Kyle Condron");
   //players[1] = new Player("Simon Helsinki");
   //Board* playingBoard = new Board();
   //Bag* shuffledBag = new Bag();
   //players[0]->Draw(shuffledBag);
   //players[0]->handToString();
   Menu* menu = new Menu();
   menu->startMenu();
   return EXIT_SUCCESS;
}
