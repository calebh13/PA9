#pragma once
#include "SFML/Graphics.hpp"

// Make Mushroom a sprite

class Mushroom : public sf::RectangleShape
{
public: 
	Mushroom(const sf::Vector2f& pos);
};