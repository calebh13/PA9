/*
	Caleb

	Description: This is the header file for the Mushroom Class

   History: 4/19/24 - Class was created and implimented initially by Caleb

*/
#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

//Mushroom inherits gameobject
class Mushroom : public GameObject
{
public: 
	//Inherited functions from gameObject
	using GameObject::GameObject; // inherit constructor
	void hit(void);
	void heal(void);
	void collideWith(GameObject* other);

private:
	//Spawns mushrooms in position
	void genNewPosition(const sf::RenderWindow& window);
};