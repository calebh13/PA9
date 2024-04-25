#include "GameWrapper.hpp"
#include "Test.hpp"

int main()
{
    //Just does randomness and runs game
    srand((unsigned int)time(0));

    /* // Remove the /* at the start of this line to run the tests:
    Test test;
    test.testRoundSetup();
    test.testSound();
    test.testGrid();
    test.testTextures();
    /**/
    
    GameWrapper game;
    game.run();
    return 0;
}