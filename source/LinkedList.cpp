
#include "LinkedList.h"
#include "iostream"
LinkedList::LinkedList() {
   head = nullptr;
   length = 0;
}

LinkedList::~LinkedList() {
    Node* next = head;
    Node* cur = NULL;
    while (next != NULL) {
        cur = next;
        next = next->getNext();
        delete cur;
    }
}

void LinkedList::addToFront(Tile *tile){
    Node* node = new Node(tile, head);
    this->head = node;
    this->length++;
}

void LinkedList::addToEnd(Tile *tile){
     // Creates a temp to hold the last node and set last's data and next
    Node* last = new Node(tile, NULL);

    //last->tile = tile;
    //last->next = NULL;

    // If the linked list is empty then set head = last
    if (head == NULL) {
        head = last;
    } else {
        // Creates a temp node and sets it to head
        //Node *temp = new Node;
        Node* temp = new Node( *head);
        //temp = head;

        // Uses temp to find the last node
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }

        // Appends the last node with last
        temp->setNext(last);
    }

}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << " " << head->getTile()->getColour() << head->getTile()->getShape() << std::endl;
        head = head->getNext();
        i++;
    }
}

void LinkedList::deleteNode(Tile tile){
   if(head->getNext() == NULL)  {
  
        /* Copy the data of next node to head */
        head->setTile(head->getNext()->getTile());  
  
        // store address of next node  
        head = head->getNext();  
  
        // Remove the link of next node  
        head->setNext(head->getNext()->getNext());  
  
        // free memory  
        free(head);  
        length--;
        return;  
        }
   Node *prev = head;  
    while(prev->getNext() != NULL && prev->getNext() != head)  
        prev = prev->getNext();  
  
    // Check if node really exists in Linked List  
    if(prev->getNext() == NULL)  
    {  
        std::cout << "\nGiven node is not present in Linked List";  
        return;  
    }  
  
    // Remove node from Linked List  
    prev->setNext(prev->getNext()->getNext());  
  
    // Free memory  
    free(head);  
    length--;
    return;  
}


//need to delete head and create copy of tile
Tile* LinkedList::getHead(){
    return head->getTile();
}
