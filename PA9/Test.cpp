#include "Test.hpp"

void Test::testTextures(void)
{
	GameWrapper* obj = new GameWrapper;
	
    //obj->textureList.at("Bullet");
    //obj->textureList.at("Body");
    //obj->textureList.at("Flea");
    //obj->textureList.at("Head");
    //obj->textureList.at("Player");
    //obj->textureList.at("Mushroom");
    //obj->textureList.at("Spider");

    // everything will be of type spider as it is just the textures we are testing 
    Spider* spider  = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .30, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Spider"), 4);
    Spider* bullet = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .35, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Bullet"), 4);
    Spider* centiBody = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .40, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Body"), 4);
    Spider* centiHead = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .45, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Head"), 4);
    Spider* player = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .50, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Player"), 4);
    Spider* mushroom = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .55, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Mushroom"), 4);
    Spider* flea = new Spider(obj->objScale, Grid::getGridPos(Grid::getGridDimension() * .60, Grid::getGridDimension() * .50, *obj->window), obj->textureList.at("Flea"), 4);


  

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