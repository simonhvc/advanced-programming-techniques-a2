#include "Player.h"

    Player::Player(std::string name)
    {
      this->name = name;
    }

    void Player::Draw(Bag* bag, int tiles){
      for(int i = 0; i < tiles; i++){
        hand->addToEnd(bag->getTile());
      }
    }

    void Player::handToString(){
       hand->print();
    }

    void Player::updateScore(int score){
      this->score += score;
    }

    int Player::getScore(){
      return score;
    }
