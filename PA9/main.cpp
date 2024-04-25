#include "GameWrapper.hpp"

int main()
{
    //Just does randomness and runs game
    srand((unsigned int)time(0));

    GameWrapper game;
    game.run();

    return 0;
}