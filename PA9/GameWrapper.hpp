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
	// prevents textures from going out of scope, accessed using the name of the GameObject
	std::map<std::string, sf::Texture> textureList;
	sf::RenderWindow* window;
	Player* player;
	void startRound(unsigned int round);
};	