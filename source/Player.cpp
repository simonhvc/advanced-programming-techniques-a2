#include <string>
class Player { 
    std::string name, studentNumber, Email;
    int score;
    Hand hand;
  
    // Default Constructor 
    Player(std::string name, std::string studentNumber, std::string Email) 
    { 
      this->name = name;
      this->studentNumber = studentNumber;
      this->Email = Email;
    } 
  
}; 
