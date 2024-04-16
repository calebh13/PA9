#include "GameWrapper.hpp"

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
    // Game loop goes here.
}
