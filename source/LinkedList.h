
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
   int length;
   LinkedList();
   ~LinkedList();
   void add(Tile tile);
   void deleteNode(Tile tile);
   void print();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
