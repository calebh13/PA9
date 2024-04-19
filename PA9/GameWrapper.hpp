#pragma once
#include "GameObject.hpp"
#include "Player.hpp"
class GameWrapper
{
public:
	GameWrapper(void);
	~GameWrapper();
	void run(void);
private:
	std::vector<GameObject*> objList; // polymorphism!
	sf::RenderWindow* window;
	Player* player;
	void startRound(unsigned int round);
};	