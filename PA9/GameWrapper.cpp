/*
    Lucas, Caleb

    Description: This the cpp file for the wrapper class of the game. It handles 
                    all game logic and running

// History: 4/20/24 - Class was created and implimented initially by Caleb
            4/24/24 - Refactored by Lucas

*/
#include "GameWrapper.hpp"
#include "GameObject.hpp"
#include "Mushroom.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Grid.hpp"
#include "CentipedeHead.hpp"


/*************************************************************
* Function: GameWrapper()   								*
* Description: Constructor. Initializes all values			*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Object Created      					    *
*************************************************************/
GameWrapper::GameWrapper(void)
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // Can be changed later
    
    int windowDimension = (int)(std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * 0.8);
    // objScale makes objects fit exactly inside 1 grid slot
    this->objScale = (float)windowDimension / (16 * Grid::getGridDimension());

    //Sets default values of the window
    window = new sf::RenderWindow(sf::VideoMode(windowDimension, windowDimension), "Centipede", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);
    window->setMouseCursorVisible(false);

    //Self-evident
    loadAssets();
    placeMushrooms();
    placeInitEntities();

}

/*************************************************************
* Function: ~GameWrapper()   								*
* Description: Destructor. Frees all game objects   		*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Object destroed      					    *
*************************************************************/
GameWrapper::~GameWrapper()
{
    delete window;
    while (!objList.empty())
    {
        objList.pop_back(); // automatically calls destructors
    }
}

/*************************************************************
* Function: placeInitEntities()								*
* Description: Places all initial entities  				*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Entities placed    					    *
*************************************************************/
void GameWrapper::placeInitEntities(void) {
    // Create player:
    this->player = new Player(this->objScale, Grid::getGridPos(12, 20, *window), textureList.at("Player"));
    // centers the texture over the cursor

    player->setOrigin((float)textureList.at("Player").getSize().x / 2, (float)textureList.at("Player").getSize().y / 2);
    objList.push_back(player);

    // Create (hidden) flea:
    this->flea = new Flea(objScale, Grid::getGridPos(30, 30, *window), textureList.at("Flea"), 1, 1);
    objList.push_back(flea);

    centipedeCounter = 0;
}

/*************************************************************
* Function: placeMushrooms()        						*
* Description: Places all initial mushrooms  				*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Mushrooms placed    					    *
*************************************************************/
void GameWrapper::placeMushrooms(void) {
    // Place initial mushrooms:
    std::vector<sf::Vector2i> used;
    for (int i = 0; i < 30; i++)
    {
        sf::Vector2i cur = sf::Vector2i(rand() % Grid::getGridDimension(), rand() % (int)(Grid::getGridDimension() / 1.25));
        // Ensure cur has not already been used and that it is not the player's position
        for (int i = 0; i < used.size(); i++)
        {
            bool foundMatch = false;
            while ((used[i].x == cur.x && used[i].y == cur.y) || (cur.x == 12 && cur.y == 20))
            {
                foundMatch = true;
                cur.x = rand() % Grid::getGridDimension();
                cur.y = rand() % (int)(Grid::getGridDimension() / 1.25);
            }
            if (foundMatch) break;
        }
        used.push_back(cur);
        objList.push_back(new Mushroom(objScale, sf::Vector2f(Grid::getGridPos(cur.x, cur.y, *window)), textureList.at("Mushroom"), 4));
    }
}

/*************************************************************
* Function: loadAssets()        							*
* Description: Inserts all textures and audios to hashmaps  *
* Input parameters: None									*
* Returns: None											    *
* Preconditions: Files must exist				            *
* Postconditions: Data structures filled				    *
*************************************************************/
void GameWrapper::loadAssets(void) {
    // Insert textures into list
    // We need to load here because otherwise the textures don't get created properly

    textureList.insert(std::pair<std::string, sf::Texture>("Mushroom", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Bullet", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Body", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Flea", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Head", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Player", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Spider", sf::Texture()));

    //Load textures
    textureList.at("Bullet").loadFromFile("assets/CEN_1BLLT.png");
    textureList.at("Body").loadFromFile("assets/CEN_1BODY.png");
    textureList.at("Flea").loadFromFile("assets/CEN_1FLEA.png");
    textureList.at("Head").loadFromFile("assets/CEN_1HEAD.png");
    textureList.at("Player").loadFromFile("assets/CEN_1PLYR.png");
    textureList.at("Mushroom").loadFromFile("assets/CEN_1SHRM.png");
    textureList.at("Spider").loadFromFile("assets/CEN_1SPDR.png");

    //Loads Audio Files
    soundList.insert(std::pair<std::string, AudioWrapper>("Shoot", AudioWrapper("assets/laser.wav")));
    soundList.insert(std::pair<std::string, AudioWrapper>("Split", AudioWrapper("assets/split.wav")));
    soundList.insert(std::pair<std::string, AudioWrapper>("Mush", AudioWrapper("assets/mushDeath.wav")));
    soundList.insert(std::pair<std::string, AudioWrapper>("PlayerDeath", AudioWrapper("assets/playerDeath.wav")));
    soundList.insert(std::pair<std::string, AudioWrapper>("SpiderDeath", AudioWrapper("assets/spiderDeath.wav")));
}

void GameWrapper::run(void)
{
    int counter = 0, round = 1;
    bool isRoundSetup = true;
    int fleaCoolDown = 2000;
    startRound(round);

    while (window->isOpen())
    {
        // Maybe change this to a multi-frame thing later
        sf::Event event;
        // pollEvent uses event as a return param for the internal event queue, so we must poll until queue is empty
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window->close();
        }

        // Get player input for shooting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (player->shoot())
            {
                // Create a new bullet and add it to list of GameObjects
                soundList.at("Shoot").play();
                objList.push_back(new Bullet(objScale, player->getPosition(), textureList.at("Bullet"), 1, 1));
            }
        }



        //flea stuff
        //spawn flea        
        fleaCoolDown--;
        if (fleaCoolDown < 0)
        {
            fleaCoolDown = 2000;
            this->flea->setPosition(Grid::getGridPos(rand() % 24, 1, *window));
        }

        // Real game loop:
        for (int i = 0; i < objList.size(); i++)
        {
            objList[i]->update(*window); // movement
            // Collision loop:
            for (int j = i + 1; j < objList.size(); j++)
            {
                if (i <= 0) i = 0;
                if (objList[i]->getGlobalBounds().intersects(objList[j]->getGlobalBounds()))
                {
                    objList[i]->collideWith(objList[j]);
                }

                switch (objList[i]->isDead())
                {
                case action::DESTROY:
                {
                    objList.erase(objList.begin() + i);
                    i--;
                    j--;
                    break;
                }

                case action::CENTIPEDE_DESTROYED:
                {
                    // This should be all the necessary code for centipede destruction.
                    objList.erase(objList.begin() + i);
                    i--;
                    j--;
                    centipedeCounter--;
                    break;
                }

                case action::CENTIPEDE_SHOT:
                {
                    soundList.at("Split").play();
                    // This means the node behind the shot part is guaranteed to not be nullptr
                    CentipedePart* shotPart = dynamic_cast<CentipedePart*>(objList[i]);
                    CentipedePart* nodeBehind = shotPart->getNodeBehind();
                    // Find last part of the centipede:
                    while (nodeBehind->getNodeBehind() != nullptr)
                    {
                        nodeBehind = nodeBehind->getNodeBehind();
                    }
                    CentipedeBody* lastBodyNode = dynamic_cast<CentipedeBody*>(nodeBehind);
                    // Important: set node behind next node to nullptr, since we'll be deleting this guy
                    lastBodyNode->getFrontNode()->setNodeBehind(nullptr);
                    GameObject* toErase = dynamic_cast<GameObject*>(lastBodyNode);
                    int eraseIndex = 0;
                    for (; eraseIndex < objList.size(); eraseIndex++)
                    {
                        if (objList[eraseIndex] == toErase)
                        {
                            break;
                        }
                    }
                    objList.push_back(new Mushroom(objScale, Grid::snapToGrid(lastBodyNode->getPosition(), objScale), textureList.at("Mushroom"), 4));
                    objList.erase(objList.begin() + eraseIndex);
                    if (eraseIndex <= i)
                    {
                        i--;
                    }
                    if (eraseIndex <= j)
                    {
                        j--;
                    }
                    shotPart->heal();
                    break;
                }
                
                case action::RESPAWN:
                {
                    player->setPosition(Grid::getGridPos(12, 20, *window));
                    soundList.at("PlayerDeath").play();
                    break;
                }

                case action::GAME_OVER:
                {
                    return;
                    break;
                }
                }

                switch (objList[j]->isDead())
                {
                case action::DESTROY:
                {
                    objList.erase(objList.begin() + j);
                    j--;
                    break;
                }
                case action::CENTIPEDE_DESTROYED:
                {
                    objList.erase(objList.begin() + i);
                    soundList.at("Split").play();
                    j--;
                    centipedeCounter--;
                    break;
                }
                case action::CENTIPEDE_SHOT:
                {
                    soundList.at("Split").play();
                    // This means the node behind the shot part is guaranteed to not be nullptr
                    CentipedePart* shotPart = dynamic_cast<CentipedePart*>(objList[j]);
                    CentipedePart* nodeBehind = shotPart->getNodeBehind();
                    // Find last part of the centipede:
                    while (nodeBehind->getNodeBehind() != nullptr)
                    {
                        nodeBehind = nodeBehind->getNodeBehind();
                    }
                    CentipedeBody* lastBodyNode = dynamic_cast<CentipedeBody*>(nodeBehind);
                    // Important: set node behind next node to nullptr, since we'll be deleting this guy
                    lastBodyNode->getFrontNode()->setNodeBehind(nullptr);
                    GameObject* toErase = dynamic_cast<GameObject*>(lastBodyNode);
                    int eraseIndex = 0;
                    for (; eraseIndex < objList.size(); eraseIndex++)
                    {
                        if (objList[eraseIndex] == toErase)
                        {
                            break;
                        }
                    }
                    objList.push_back(new Mushroom(objScale, Grid::snapToGrid(lastBodyNode->getPosition(), objScale), textureList.at("Mushroom"), 4));
                    objList.erase(objList.begin() + eraseIndex);
                    if (eraseIndex <= i)
                    {
                        i--;
                    }
                    if (eraseIndex <= j)
                    {
                        j--;
                    }
                    shotPart->heal();
                    break;
                }
                case action::RESPAWN:
                {
                    player->setPosition(Grid::getGridPos(12, 20, *window));
                    soundList.at("PlayerDeath").play();
                    break;
                }
                case action::GAME_OVER:
                {
                    return;
                    break;
                }
                }
            }
        }

        // If flea is in bounds and good random value, spawn a mushroom
        if ((rand() % 100) <= 5 && this->flea->getPosition().y > 0 && this->flea->getPosition().y < Grid::getGridPos(0, 24, *window).y)
        {
            objList.push_back(new Mushroom(objScale, Grid::snapToGrid(this->flea->getPosition(), *window), textureList.at("Mushroom"), 4, 1));
        }
        
        window->clear();

        // Draw loop: 
        for (int i = 0; i < objList.size(); i++)
        {
            window->draw(*(objList[i]));
        }

        window->draw(*player);

        window->display();
        counter++;
        player->reduceShotTimer();
        if (centipedeCounter <= 0)
        {
            round++;
            startRound(round);
        }
    }
}

void GameWrapper::startRound(unsigned int round)
{
    // Palette swaps:
    int palette = (round - 1) % 8 + 1;
    std::string base = "assets/CEN_" + std::to_string(palette);

    textureList.at("Bullet").loadFromFile(base + "BLLT.png");
    textureList.at("Body").loadFromFile(base + "BODY.png");
    textureList.at("Flea").loadFromFile(base + "FLEA.png");
    textureList.at("Head").loadFromFile(base + "HEAD.png");
    textureList.at("Player").loadFromFile(base + "PLYR.png");
    textureList.at("Mushroom").loadFromFile(base + "SHRM.png");
    textureList.at("Spider").loadFromFile(base + "SPDR.png");

    

    // Heal mushrooms (does nothing for all other objects)
    for (int i = 1; i < objList.size(); i++)
    {
        objList[i]->heal();
    }
    
    // Now we create a new centipede object
    // Spawn a centipede right above the top of the screen, and it will go down 1 square then immediately go right

    CentipedeHead* head = new CentipedeHead(objScale, Grid::getGridPos(2, 1, *window), \
        textureList.at("Head"), 1, CENTIPEDE_SPEED, DOWN, RIGHT);
    CentipedeHead* head2 = new CentipedeHead(objScale, Grid::getGridPos(Grid::getGridDimension() - 2, 1,  *window), \
        textureList.at("Head"), 1, CENTIPEDE_SPEED, DOWN, LEFT);
    centipedeCounter = 2;
    CentipedePart* cur = head;
    CentipedePart* cur2 = head2;
    objList.push_back(head);
    objList.push_back(head2);

    for (int i = 1; i <= 12; i++)
    {
        CentipedeBody* nextNode = new CentipedeBody(objScale, Grid::getGridPos(2, -i + 1, *window),\
            textureList.at("Body"), 1, CENTIPEDE_SPEED, DOWN, cur);
        CentipedeBody* nextNode2 = new CentipedeBody(objScale, Grid::getGridPos(Grid::getGridDimension() - 2, -i + 1, *window), \
            textureList.at("Body"), 1, CENTIPEDE_SPEED, DOWN, cur2);
        objList.push_back(nextNode);
        objList.push_back(nextNode2);
        cur = nextNode;
        cur2 = nextNode2;
    }

    // Spawn spider 
    objList.push_back(new Spider(objScale, Grid::getGridPos(0, Grid::getGridDimension() * .85, *window), textureList.at("Spider"), 4));

    // set player position to center
    player->setPosition(Grid::getGridPos(12, 20, *window));
}