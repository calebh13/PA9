#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Mushroom.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "GameWrapper.hpp"

int main()
{
    GameWrapper game;
    game.run();

    return 0;
}