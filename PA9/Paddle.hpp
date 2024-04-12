#pragma once
#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
public:
	Paddle(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
		this->setFillColor(color);
	}
private:
};