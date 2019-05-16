#include "Player.h"

    Player::Player(std::string name, std::string studentNumber, std::string Email)
    {
      this->name = name;
      this->studentNumber = studentNumber;
      this->Email = Email;
    }

    void Player::Draw(Bag* bag, int amount){
      for(int i = 0; i < amount; i++){
        hand->addToEnd(bag->getTile());
      }

    }

    void Player::handToString(){
       hand->print();
    }
