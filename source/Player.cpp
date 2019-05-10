#include <string>
#include <linkedList>
#include <bag>
class Player { 
    std::string name, studentNumber, Email;
    int score;
    linkedList hand = new linkedList();
  
    // Default Constructor 
    Player(std::string name, std::string studentNumber, std::string Email) 
    { 
      this->name = name;
      this->studentNumber = studentNumber;
      this->Email = Email;
    } 

    void Draw(Bag bag, int amount){
      for(int i = 0; i < amount; i++){
        hand->add(bag->getHead());
      }
      
    }

    std:string handToString(){
      // cycle through linked list and add comma text +=
    }
  
}; 
