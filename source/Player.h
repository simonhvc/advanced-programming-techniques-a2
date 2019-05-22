#include <string>
#include "LinkedList.h"
#include "Bag.h"

class Player {

    public:
        Player(std::string name, int score);

        void Draw(Bag* bag, int tiles);

        std::string handToString();

        std::string getName();
        Tile* hasTile(char color, int shape);

        void updateScore(int score);

        void addToHand(Tile* tile);

        int getScore();

    private:
        std::string name;
        int score;
        LinkedList* hand = new LinkedList();
};
