#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Mushroom.hpp"
#include "GameWrapper.hpp"

int main()
{
    GameWrapper game;

    sf::Texture texture1;
    texture1.loadFromFile("assets/CEN_1SHRM.png");

    Mushroom m1 = Mushroom(sf::Vector2f(10, 10), sf::Vector2f(0, 0), texture1, 4);
    int counter = 0;

    sf::Clock clock;

    while (game.window->isOpen())
    {
        sf::Event event;
        while (game.window->pollEvent(event)) // pollEvent uses event as a return param for the internal event queue
        {
            if (event.type == sf::Event::Closed) game.window->close();
        }

        if (counter >= 60 && !m1.isDead())
        {
            std::cout << "hit\n";
            m1.hit();
            counter = 0;
        }

        game.window->clear();

        //Makes the mushroom slide across the screen
        if (counter % 10 == 0) {
            m1.glideTo((float) counter, (float) counter);
        }
        m1.update();
        game.window->draw(m1);

        game.window->display();


        counter++;
    }

    return 0;
}