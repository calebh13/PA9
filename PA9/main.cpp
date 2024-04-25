#include "GameWrapper.hpp"

int main()
{
    srand((unsigned int)time(0));

    // TEST TEXTURE
    Test obj;
    obj.testObjMovement();

    GameWrapper game;
    //game.run();

    return 0;
}