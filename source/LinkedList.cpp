
#include "LinkedList.h"
#include "iostream"
#include <time.h>
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
    Node* temp = new Node(tile, NULL);

    //last->tile = tile;
    //last->next = NULL;

    // If the linked list is empty then set head = last
    if (!head) {
        head = temp;
        return;
    } else {
        // Creates a temp node and sets it to head
        //Node *temp = new Node;
        Node* last = new Node( *head);
        //temp = head;

        // Uses temp to find the last node
        while (last->getNext() != NULL) {
            last = last->getNext();
            last->setNext(temp->getNext());
        }

        // Appends the last node with last
        last->setNext(temp);
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

//Need to delete tile after returning it
Tile* LinkedList::getRandomTile() {
    //Sets the random Seed
    srand(time(NULL));
    //Gets a random integer between 0 and the length of the array
    int randomIndex = 0 + (rand() % static_cast<int>(length - 0 + 1));
    //The index to increment
    int i = 0;

    //Gets the header
    Node* node = this->head;

    while (i < randomIndex) {
      node = node->getNext();
      i++;
    }

    Tile* tile = node->getTile();
    return tile;
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
