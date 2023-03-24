#include"player.hpp"
namespace ariel
{
    class Game{
        public:
    Game(Player player1,Player  player2){}
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    };
}
