#pragma once
#include "GameObject.hpp"
#include "Player.hpp"
#include "AudioWrapper.hpp"
#include <unordered_map>
class GameWrapper
{
public:
	GameWrapper(void);
	~GameWrapper();
	void run(void);
private:
	// IMPORTANT NOTE: player will always be at index 0 of objList.
	std::vector<GameObject*> objList; // polymorphism!
	float objScale;
	// prevents textures from going out of scope, accessed using the name of the GameObject (hash table)
	std::unordered_map<std::string, sf::Texture> textureList;
	std::unordered_map<std::string, AudioWrapper> soundList;
	sf::RenderWindow* window;
	Player* player;
	unsigned int centipedeCounter;

	void startRound(unsigned int round);
};	