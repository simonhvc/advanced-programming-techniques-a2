
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

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->tile << std::endl;
        head = head->next;
        i++;
    }
}

void LinkedList::deleteNode(Tile tile){
   if(head->next == NULL)  
  
        /* Copy the data of next node to head */
        head->data = head->next->data;  
  
        // store address of next node  
        n = head->next;  
  
        // Remove the link of next node  
        head->next = head->next->next;  
  
        // free memory  
        free(n);  
  
        return;  
        }
   Node *prev = head;  
    while(prev->next != NULL && prev->next != n)  
        prev = prev->next;  
  
    // Check if node really exists in Linked List  
    if(prev->next == NULL)  
    {  
        cout << "\nGiven node is not present in Linked List";  
        return;  
    }  
  
    // Remove node from Linked List  
    prev->next = prev->next->next;  
  
    // Free memory  
    free(n);  
  
    return;  
}
