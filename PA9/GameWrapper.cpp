#include "GameWrapper.hpp"
#include "Mushroom.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Grid.hpp"

GameWrapper::GameWrapper(void)
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 5; // Can be changed later
    
    int windowDimension = (int)(std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * 0.8);
    // objScale makes objects fit exactly inside 1 grid slot
    this->objScale = (float)windowDimension / (16 * Grid::getGridDimension());

    window = new sf::RenderWindow(sf::VideoMode(windowDimension, windowDimension), "Centipede", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);
    window->setMouseCursorVisible(false);

    // Create player:
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/CEN_7HEAD.png"); // change to player texture later
    textureList["Player"] = playerTexture;
    this->player = new Player(this->objScale, Grid::getGridPos(12, 20, *window), textureList.at("Player"));
    this->player->setOrigin((float)playerTexture.getSize().x / 2, (float)playerTexture.getSize().y / 2); // centers the texture over the cursor
    objList.push_back(this->player);
}

GameWrapper::~GameWrapper()
{
    delete window;
    while (!objList.empty())
    {
        objList.pop_back(); // automatically calls destructors
    }
}

void GameWrapper::run(void)
{
    sf::Texture shroomTexture, bulletTexture;
    shroomTexture.loadFromFile("assets/CEN_1SHRM.png");
    bulletTexture.loadFromFile("assets/CEN_1BLLT.png");
    textureList.insert(std::pair<std::string, sf::Texture>("Mushroom", shroomTexture));
    textureList.insert(std::pair<std::string, sf::Texture>("Bullet", bulletTexture));

    //sf::Texture bulletTexture;
    //bulletTexture.loadFromFile();

    objList.push_back(new Mushroom(objScale, sf::Vector2f(Grid::getGridPos(8, 8, *window)), textureList.at("Mushroom"), 4));
    GameObject* m1 = objList.back();

    int counter = 0;

    while (window->isOpen())
    {
        sf::Event event;
        // pollEvent uses event as a return param for the internal event queue, so we must poll until queue is empty
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window->close();
            if (event.type == sf::Event::MouseButtonPressed) // we can check if its a left click or right click later
            {
                if (player->canShoot())
                {
                    // Create a new bullet and add it to list of GameObjects
                    objList.push_back(new Bullet(2, player->getPosition(), textureList.at("Bullet"), 1, 1));
                }
            }
        }

        if (counter % 60 == 1 && !m1->isDead())
        {
            std::cout << "hit\n";
            m1->hit();
        }

        window->clear();

        // Real game loop:
        for (int i = 0; i < objList.size(); i++)
        {
            objList[i]->update(*window); // movement
            // now handle collision stuff: e.g. bullet hitting mushroom, centipede, etc.
        }
        
        // Draw loop: 
        for (int i = 0; i < objList.size(); i++)
        {
            window->draw(*(objList[i]));
        }

        window->display();
        counter++;
    }
}
void GameWrapper::startRound(unsigned int round)
{
    // Do palette swaps, generate mushrooms, create a new centipede object, etc.
    // Because this takes multiple frames, maybe need to make some sort of status enum in gamewrapper
    // that allows us to pause for animations?
    
    // set player position to center (and delete a mushroom if it's there)
}