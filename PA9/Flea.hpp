/*
	Elliot, Caleb
	4/22/24

	Description: This is the header file for the Flea Class

   History: 4/22/24 - Class was created and implimented initially by Elliot
			4/23/24 - Some code was refactord and collision added by Caleb

*/

//Including libraries
#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"

//Flea extends game object
class Flea : public GameObject
{
public:
	using GameObject::GameObject;

	//Functions inherited from Game Object
	void collideWith(GameObject* other);
	void hit(void);
	enum action isDead(void) const;

private:
	//Generates new positions for flea
	void genNewPosition(const sf::RenderWindow& window);

	//Fleas have special behaviour when colliding with mushrooms
	bool collidingWithMushroom;
};