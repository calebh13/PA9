#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    clock.restart();

    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
        // Now make all physics and rendering calculations based on dt.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

        clock.restart(); // don't forget to clock.restart() !
    }

    return 0;
}