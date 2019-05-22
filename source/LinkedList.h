
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include "Tile.h"
#include "iostream"
#include <time.h>

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   void addToFront(Tile *tile);
   void addToEnd(Tile *tile);
   void deleteNode(Tile tile);
   void print();
   Tile* hasTile(char color, int shape);
   Tile* getRandomTile();
   Tile* getHead();

//private:
   Node* head;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H
