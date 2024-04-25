#include "Test.hpp"

/*
* Function: testRoundSetup()
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



/************************************************************
* Function: testTextures()                                  *
* Description: Tests the textures to ensure they have been  *
* loaded properly - displays these textures                 *
* Input parameters: Pointer to object that was hit          *
* Returns: None                                             *
* Preconditions: input pointer cannot be nullptr            *
* Postconditions: Object's parameters are changed on hit    *
*************************************************************/
void Test::testTextures(void)
{
	GameWrapper* obj = new GameWrapper;
	
    // Everything will be of type spider as it is just the textures we are testing - Inilizes texture to object spider
    Spider* spider  = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .30, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Spider"), 4);
    Spider* bullet = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .35, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Bullet"), 4);
    Spider* centiBody = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .40, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Body"), 4);
    Spider* centiHead = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .45, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Head"), 4);
    Spider* player = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .50, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Player"), 4);
    Spider* mushroom = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .55, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Mushroom"), 4);
    Spider* flea = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .60, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Flea"), 4);

    // Draws objects until program is terminated
    while (obj->window->isOpen())
    {
        obj->window->draw(*spider);
        obj->window->draw(*bullet);
        obj->window->draw(*centiBody);
        obj->window->draw(*centiHead);
        obj->window->draw(*player);
        obj->window->draw(*mushroom);
        obj->window->draw(*flea);
        obj->window->display();
    }
}

/************************************************************
* Function: testObjMovement()                               *
* Description: Tests gliding capatilies with each object    *
* Input parameters: void                                    *
* Returns: None                                             *
*************************************************************/
void Test::testObjMovement(void)
{
    GameWrapper* obj = new GameWrapper;
    Spider* spider = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .30, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Spider"), 4);
    Spider* centiHead = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .45, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Head"), 4);

    
    while (obj->window->isOpen())
    {
        obj->window->clear(); // An object is drawn every frame so we must clear so theres no overlapping graphics 
  
        int chance = rand() % 60; // randomly generated chance so generation is not too quick
 
        if (chance == 0) 
        {
            int x = rand() % obj->window->getSize().x, y = rand() % obj->window->getSize().y;
            std::cout << "Randomly Generated Coords: " << x << ", " << y << std::endl;
            spider->glideTo(x, y);
        }
        if (sf::Mouse::isButtonPressed)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                int x = sf::Mouse::getPosition().x, y = sf::Mouse::getPosition().y;
                std::cout << "Position Clicked: " << x << ", " << y << std::endl;
                centiHead->glideTo(x, y);
            }
        }

        spider->update(*obj->window);
        centiHead->update(*obj->window);
        obj->window->draw(*spider);
        obj->window->draw(*centiHead);
        obj->window->display();
    }
}