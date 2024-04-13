#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Player : public GameObject
{
public:
	Player(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 0, unsigned int lives = 5) : GameObject(scale, pos, texture, health)
	{
		this->lives = lives;
	}
	
	void hit();
private:
	unsigned int lives;
};