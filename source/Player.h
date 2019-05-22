#include <string>
#include "LinkedList.h"
#include "Bag.h"

class Player {

    public:
        Player(std::string name);

        void Draw(Bag* bag, int tiles);

        std::string handToString();

        std::string getName();
        Tile* hasTile(char color, int shape);

        void deleteTile(char color, int shape);

        void updateScore(int score);

        void setName(std::string name);
        
        int getScore();

    private:
        std::string name, studentNumber, Email;
        int score;
        LinkedList* hand = new LinkedList();
};
