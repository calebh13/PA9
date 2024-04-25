#include "test.hpp"


//check is pointers in the Wrapper are initialized
void Test::testRoundSetup()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	if (pGameWrapper->GameWrapperTest())
	{
		std::cout << "GameWrapper pointers initialized!\n";
	}
	else
	{
		std::cout << "GameWrapper pointers are not initialized.\n";
	}
	delete pGameWrapper;
}

//play all the sounds one by one
void Test::testSound()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	system("pause");
	pGameWrapper->soundList.at("Shoot").play();
	std::cout << "did you hear the shoot sound?\n";
	system("pause");

	pGameWrapper->soundList.at("Split").play();
	std::cout << "did you hear the Split sound?\n";
	system("pause");

	pGameWrapper->soundList.at("Mush").play();
	std::cout << "did you hear the Mush sound?\n";
	system("pause");

	pGameWrapper->soundList.at("PlayerDeath").play();
	std::cout << "did you hear the PlayerDeath sound?\n";
	system("pause");

	pGameWrapper->soundList.at("SpiderDeath").play();
	std::cout << "did you hear the SpiderDeath sound?\n";
	system("pause");
	delete pGameWrapper;
}

// test if grid functions give correct converitions
void Test::testGetGrigPos()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	
	
	if (Grid::getGridPos(12, 12, *pGameWrapper->window).y == 480 && Grid::getGridPos(12, 12, *pGameWrapper->window).x == 480)
	{
		std::cout << "getGridPos works!\n";
	}
	else
	{
		std::cout << "getGridPos does not work!\n";
	}
	
	
	delete pGameWrapper;
}

//test snap to grid
void Test::testSnapToGrid()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	sf::Vector2f pos;
	pos.x = 485;
	pos.y = 485;

	if (Grid::snapToGrid(pos, *pGameWrapper->window).y == 480 && Grid::snapToGrid(pos, *pGameWrapper->window).x == 480)
	{
		std::cout << "snapToGrid works!\n";
	}
	else
	{
		std::cout << "snapToGrid does not work!\n";
	}


	delete pGameWrapper;
}

void Test::testgetGridIndices()
{
	GameWrapper* pGameWrapper = new GameWrapper;
	sf::Vector2f pos;
	pos.x = 480;
	pos.y = 480;

	if (Grid::getGridIndices(pos, *pGameWrapper->window).y == 12 && Grid::getGridIndices(pos, *pGameWrapper->window).x == 12)
	{
		std::cout << "getGridIndices works!\n";
	}
	else
	{
		std::cout << "getGridIndices does not work!\n";
	}


	delete pGameWrapper;
}
