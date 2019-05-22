
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
    if (head == nullptr) {
        head = last;
        return;
    } else {
        // Creates a temp node and sets it to head
        //Node *temp = new Node;
        Node* temp = this->head;
        //temp = head;

        // Uses temp to find the last node
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }

        // Appends the last node with last
        temp->setNext(last);
    }
    length++;

}

std::string LinkedList::print(){
    Node* head = this->head;
    std::string text;
    int i = 1;
    while(head){
        text += head->getTile()->toString() + " ";
        head = head->getNext();
        i++;
    }
    return text;
}

//Need to delete tile after returning it
Tile* LinkedList::getRandomTile() {
    //Sets the random Seed
    srand(time(NULL) + length);
    //Gets a random integer between 0 and the length of the array
    int randomIndex = 0 + (rand() % static_cast<int>(length - 0 + 1));

    //Gets the header
    Node* node = this->head;

    for(int i = 0; i < randomIndex - 1; i++) {
      if (node->getNext() != NULL) {
        node = node->getNext();
      }

    }

    Tile* tile = new Tile(*node->getTile());
    deleteNode(node->getTile()->getColour(), node->getTile()->getShape());

    return tile;
}

Tile* LinkedList::hasTile(char color, int shape) {
  bool foundTile = false;
  Node* node = this->head;
  Tile* returnTile = nullptr;

  while(node != NULL && !foundTile) {
    if (node->getTile()->getColour() == color && node->getTile()->getShape() == shape) {
      returnTile = node->getTile();
      foundTile = true;
    }
    node = node->getNext();
  }
  return returnTile;
}


void LinkedList::deleteNode(char color, int shape){

    //Gets the start of the list
    Node* node = this->head;
    bool hasFoundTile = false;
    int index = 0;

    //Checks the first node
    if (node->getTile()->getColour() == color && node->getTile()->getShape() == shape) {
      this->head = node->getNext();
      free(node);
      hasFoundTile = true;
    }

    //Loops while node has next
    while(node->getNext() != NULL && !hasFoundTile) {
      //Gets the tile
      Node* prevNode = node;
      Node* currNode = node->getNext();
      Node* nextNode = node->getNext()->getNext();

      //Checks if tile is equal to parameter
      if (currNode->getTile()->getColour() == color && currNode->getTile()->getShape() == shape) {

        if (nextNode != NULL) {
          prevNode->setNext(nextNode);
          free(currNode);
        }
        else {
          prevNode->setNext(NULL);
          free(currNode);
        }
        hasFoundTile = true;

        std::cout << "FOUND!" << '\n';
      }

      index++;
      node = node->getNext();
    }

    length--;
    return;
}


//need to delete head and create copy of tile
Tile* LinkedList::getHead(){
    return head->getTile();
}
