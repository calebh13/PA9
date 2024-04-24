#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"

class Flea : public GameObject
{
public:
	using GameObject::GameObject;
	// Fleas don't do anything other than drop down, and they only collide w/ the player
	void collideWith(GameObject* other);
	void hit(void);
	enum action isDead(void) const;

private:
	void genNewPosition(const sf::RenderWindow& window);
	bool collidingWithMushroom;
};