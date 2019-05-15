
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   length = 0;
}

LinkedList::~LinkedList() {
    Node* next = head;
    Node* cur = NULL;
    while (next != NULL) {
        cur = next;
        next = next->next;
        delete cur;
    }
}

void LinkedList::add(Tile tile){
    Node* node = new Node(tile, next);
    this->head = node;
    this->length++;
}

