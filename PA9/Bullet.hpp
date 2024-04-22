#pragma once
#include "GameObject.hpp"
#include "CentipedeBody.hpp"
#include "Mushroom.hpp"
#include "Spider.hpp"
#include "CentipedeHead.hpp"
#include "Flea.hpp"

class Bullet : public GameObject
{
public:
	Bullet(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 1)
		: GameObject(scale, pos, texture, health, interpolationFrames)
	{
		// Make all bullets centered
		this->setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().y / 2);
	}
	
	void collideWith(GameObject* other);
private:
	void genNewPosition(const sf::RenderWindow& window);

	//void collide(CentipedeBody* cenBody);
	//void collide(Mushroom* mushroom);
};