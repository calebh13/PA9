#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.hpp"

class Mushroom : public GameObject
{
public: 
	using GameObject::GameObject; // inherit constructor
	void hit();
};