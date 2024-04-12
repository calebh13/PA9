#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Ball.hpp"
#include "Paddle.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 5; // Can be changed later

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    //sf::CircleShape shape(100.f);

    Ball gameBall(200, sf::Vector2f(300, 300), sf::Color::Red);
    Paddle p1Paddle(sf::Vector2f(20, 200), sf::Vector2f(0, 400), sf::Color::White),
           p2Paddle(sf::Vector2f(20, 200), sf::Vector2f(980, 400), sf::Color::White);
    //shape.setFillColor(sf::Color::Green);

    sf::VertexArray rect(sf::Quads, 4);
    // Note: VertexArray requires vertices to be in EITHER
    // clockwise or counter-clockwise order! Choose 1, but be consistent.
    rect[0] = sf::Vertex(sf::Vector2f(500, 500), sf::Color::Yellow);
    rect[1] = sf::Vertex(sf::Vector2f(500, 550), sf::Color::Magenta);
    rect[2] = sf::Vertex(sf::Vector2f(550, 550), sf::Color::Magenta);
    rect[3] = sf::Vertex(sf::Vector2f(550, 500), sf::Color::Yellow);

    sf::Clock clock;
    clock.restart();

    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
        // Now make all physics and rendering calculations based on dt.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // While velocity is less than max velocity, add acceleration
            // Or use a constant speed
        }

        window.clear();
        window.draw(rect);
        window.display();

        clock.restart(); // don't forget to clock.restart() !
    }

    return 0;
}