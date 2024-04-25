#include "Test.hpp"

/*
* Function: collideWith()
* Description: Test if the pointers in the Game Wrapper are initialized.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*/
void Test::testRoundSetup()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	// Test dynamically allocated objects
	if (pGameWrapper->window != nullptr && pGameWrapper->player != nullptr && pGameWrapper->flea != nullptr)
	{
		bool isNullptr = false;
		for (int i = 0; i < pGameWrapper->objList.size(); i++)
		{
			if (pGameWrapper->objList[i] == nullptr)
			{
				isNullptr = true;
				break;
			}
		}
		if (isNullptr == false)
		{
			std::cout << "GameWrapper pointers initialized! Test passed.\n";
		}
		else
		{
			std::cout << "Nullptr detected in objList. Test failed.\n";
		}
	}
	else
	{
		std::cout << "GameWrapper pointers are not initialized. Test failed.\n";
	}
	delete pGameWrapper;
}

/*
* Function: testSound()
* Description: Play each sound and ask user if they herd it.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*/
void Test::testSound()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	system("pause");
	pGameWrapper->soundList.at("Shoot").play();
	std::cout << "Did you hear the shoot sound?\n";
	system("pause");

	pGameWrapper->soundList.at("Split").play();
	std::cout << "Did you hear the Split sound?\n";
	system("pause");

	pGameWrapper->soundList.at("Mush").play();
	std::cout << "Did you hear the Mush sound?\n";
	system("pause");

	pGameWrapper->soundList.at("PlayerDeath").play();
	std::cout << "Did you hear the PlayerDeath sound?\n";
	system("pause");

	pGameWrapper->soundList.at("SpiderDeath").play();
	std::cout << "Did you hear the SpiderDeath sound?\n";
	system("pause");
	delete pGameWrapper;
}

/*
* Function: testGrid()
* Description: test all grid functions
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*/
void Test::testGrid()
{
	// Run a test position through all the Grid functions, and make sure it preserves the location
	GameWrapper* pGameWrapper = new GameWrapper;
	sf::Vector2f testPos = Grid::getGridPos(12, 15, *(pGameWrapper->window));
	sf::Vector2i indices = Grid::getGridIndices(testPos, *(pGameWrapper->window));
	sf::Vector2f indicesPos = Grid::getGridPos(indices.x, indices.y, *(pGameWrapper->window));
	testPos = Grid::snapToGrid(testPos, *(pGameWrapper->window));
	indicesPos = Grid::snapToGrid(indicesPos, *(pGameWrapper->window));
	sf::Vector2i newTestIndices = Grid::getGridIndices(testPos, *(pGameWrapper->window));
	sf::Vector2i newIndices = Grid::getGridIndices(indicesPos, *(pGameWrapper->window));
	if (newIndices.x == newTestIndices.x && newIndices.y == newTestIndices.y && newIndices.x == 12 && newIndices.y == 15)
	{
		std::cout << "Grid functions work correctly. Test passed.\n";
	}
	else
	{
		std::cout << "Grid functions do not work correctly. Test failed.\n";
	}
}


