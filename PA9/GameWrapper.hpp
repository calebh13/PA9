/*
	Lucas, Caleb

	Description: This the header file for the wrapper class of the game

// History: 4/20/24 - Class was created and implimented initially by Caleb
			4/24/24 - Refactored by Lucas

*/
#pragma once
#include "GameObject.hpp"
#include "Player.hpp"
#include "AudioWrapper.hpp"
#include "Flea.hpp"
#include "Test.hpp"
#include <unordered_map>
#include "Test.hpp"

constexpr unsigned int CENTIPEDE_SPEED = 6;

class GameWrapper
{
	friend class Test;
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
	Flea* flea;
	unsigned int centipedeCounter;

	//Helper functions for constructor
	void loadAssets();
	void placeMushrooms();
	void placeInitEntities();

	void startRound(unsigned int round);
};	