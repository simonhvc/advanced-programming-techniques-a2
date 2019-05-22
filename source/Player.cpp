#include "Player.h"
#include <iostream>

    Player::Player(std::string name, int score):name(name),score(score)
    {
      
    }

    void Player::Draw(Bag* bag, int tiles){
      for(int i = 0; i < tiles; i++){
        hand->addToEnd(bag->getTile());
      }
    }

    void Player::addToHand(Tile* tile){
        this->hand->addToEnd(tile);
    }

    std::string Player::getName() {
      return name;
    }

    void Player::deleteTile(char color, int shape) {
      hand->deleteNode(color, shape);
    }

    std::string Player::handToString(){
       return hand->print();
    }

    Tile* Player::hasTile(char color, int shape) {
      Tile* tile = hand->hasTile(color, shape);
      return tile;
    }

    void Player::updateScore(int score){
      this->score += score;
    }

    int Player::getScore(){
      return score;
    }
