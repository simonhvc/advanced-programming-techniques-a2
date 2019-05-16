
#include "LinkedList.h"
#include "Player.h"
#include "Board.h"
#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   std::cout << "TODO: Implement Qwirkle!" << std::endl;
   Player* players[20];
   players[0] = new Player("Kyle Condron", "s3717110", "s3717110@student.rmit.edu.au");
   players[1] = new Player("Simon Helsinki", "s3694451", "sblahlbah@blah.yes");
   //Board* playingBoard = new Board();
   Bag* shuffledBag = new Bag();
   players[0]->Draw(shuffledBag);
   players[0]->handToString();
   return EXIT_SUCCESS;
}
