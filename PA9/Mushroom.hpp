#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"

class Mushroom : public GameObject
{
public: 
	using GameObject::GameObject; // inherit constructor
	void hit(void);
	void heal(void);

	void collideWith(GameObject* other);
private:
	void genNewPosition(const sf::RenderWindow& window);
};