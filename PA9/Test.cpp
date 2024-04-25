#include "Test.hpp"



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