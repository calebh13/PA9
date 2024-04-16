#pragma once
#include "GameObject.hpp"
class GameWrapper
{
public:
	GameWrapper(void);
	void run(void);
	sf::RenderWindow* window; // public for now, but this should be changed later
private:
	std::vector<GameObject*> list;
};	