#pragma once
#include "GameObject.hpp"

class Mushroom : public GameObject
{
public: 
	using GameObject::GameObject; // inherit constructor
	void hit(void);
private:
	void genNewPosition(const sf::RenderWindow& window);
};