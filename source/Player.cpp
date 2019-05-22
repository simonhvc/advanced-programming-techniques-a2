#include "Player.h"
#include <iostream>

    Player::Player(std::string name)
    {
      this->name = name;
    }

    void Player::Draw(Bag* bag, int tiles){
      for(int i = 0; i < tiles; i++){
        hand->addToEnd(bag->getTile());
      }
    }

    std::string Player::getName() {
      return name;
    }

    void Player::handToString(){
       hand->print();
    }

    Tile* Player::hasTile(char color, int shape) {
      std::cout << "im here" << '\n';
      Tile* tile = hand->hasTile(color, shape);
      std::cout << "now im here" << '\n';
      return tile;
    }

    void Player::updateScore(int score){
      this->score += score;
    }

    int Player::getScore(){
      return score;
    }
