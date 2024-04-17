#include "GameWrapper.hpp"
#include "Mushroom.hpp"

GameWrapper::GameWrapper(void)
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 5; // Can be changed later
    
    int windowDimension = (int)(std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * 0.8);

    window = new sf::RenderWindow(sf::VideoMode(windowDimension, windowDimension), "Centipede", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);
}

void GameWrapper::run(void)
{

    sf::Texture texture1;
    texture1.loadFromFile("assets/CEN_1SHRM.png");

    Mushroom m1 = Mushroom(sf::Vector2f(10, 10), sf::Vector2f(0, 0), texture1, 4);
    int counter = 0;

    sf::Clock clock;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) // pollEvent uses event as a return param for the internal event queue
        {
            if (event.type == sf::Event::Closed) window->close();
        }

        if (counter >= 60 && !m1.isDead())
        {
            std::cout << "hit\n";
            m1.hit();
            counter = 0;
        }

        window->clear();

        //Makes the mushroom slide across the screen
        if (counter % 10 == 0) {
            m1.glideTo((float)counter, (float)counter);
        }
        m1.update();
        window->draw(m1);
        // setFramerateLimit causes a sleep function to be implicitly called right here, after draw() finishes
        window->display();

        counter++;
    }
}
