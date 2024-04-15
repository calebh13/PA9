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

    Mushroom m1 = Mushroom(sf::Vector2f(5, 5), sf::Vector2f(300, 300), texture1, 4);
    int counter = 0;

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); // clock.restart() returns time elapsed
        // Movement should rely on dt; if FPS is low, then dt is high, so things should move more.
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
        else if (m1.isDead())
        {
            // once we have vectors of things to draw, delete m1 from vector
        }

        window.clear();
        window.draw(m1);
        window.display();

        counter++;
    }

    return 0;
}