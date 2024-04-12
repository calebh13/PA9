#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(float radius = 0, const sf::Vector2f& pos = sf::Vector2f(), const sf::Color& color = sf::Color()) : CircleShape(radius)
	{
		this->setPosition(pos);
		this->setFillColor(color);
	}
private:
};