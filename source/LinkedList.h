
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
   int length;
   LinkedList();
   ~LinkedList();
   void add(int data);
   void print();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
