#pragma once
#include "GameObject.hpp"
class GameWrapper
{
public:
	GameWrapper(void);
	~GameWrapper();
	void run(void);
private:
	std::vector<GameObject*> objList;
	sf::RenderWindow* window; // public for now, but this should be changed later

	void startRound(unsigned int round);
};	