#pragma once
#include "GameObject.hpp"

class Mushroom : public GameObject
{
public: 
	using GameObject::GameObject; // inherit constructor
	void hit(void);
	void heal(void);
private:
	void genNewPosition(const sf::RenderWindow& window);
};