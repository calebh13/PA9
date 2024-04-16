#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Mushroom.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 5; // Can be changed later

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Centipede");
    window.setFramerateLimit(60);

    sf::Texture texture1;
    texture1.loadFromFile("assets/CEN_1SHRM.png");

    Mushroom m1 = Mushroom(sf::Vector2f(5, 5), sf::Vector2f(0, 0), texture1, 4);
    int counter = 0;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) // pollEvent uses event as a return param for the internal event queue
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (counter >= 60 && !m1.isDead())
        {
            std::cout << "hit\n";
            m1.hit();
            counter = 0;
        }

        window.clear();


        //Makes the mushroom slide across the screen
        if (counter % 10 == 0) {
            m1.glideTo((float) counter, (float) counter);
        }
        m1.update();
        window.draw(m1);

        window.display();


        counter++;
    }

    return 0;
}