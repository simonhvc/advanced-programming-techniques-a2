#include "Player.h"

    Player::Player(std::string name)
    {
      this->name = name;
    }

    void Player::Draw(Bag* bag){
        hand->addToEnd(bag->getTile());
    }

    void Player::handToString(){
       hand->print();
    }
