#include <string>
#include <LinkedList.h>
#include <Bag.cpp>
class Player { 
    std::string name, studentNumber, Email;
    int score;
    LinkedList* hand = new LinkedList();
  
    // Default Constructor 
    Player(std::string name, std::string studentNumber, std::string Email) 
    { 
      this->name = name;
      this->studentNumber = studentNumber;
      this->Email = Email;
    } 

    void Draw(Bag bag, int amount){
      for(int i = 0; i < amount; i++){
        hand->add(bag.getTile());
      }
      
    }

    void handToString(){
       hand->print();
    }

  
}; 
