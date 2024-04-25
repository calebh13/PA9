#include "GameWrapper.hpp"
#include "Test.hpp"

int main()
{
    srand((unsigned int)time(0));

    /* // Remove the /* at the start of this line to run the tests:
    Test test;
    test.testRoundSetup();
    test.testSound();
    test.testGrid();
    /**/
    
    GameWrapper game;
    game.run();



    return 0;
}