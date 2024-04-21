#include "GameWrapper.hpp"
#include "Mushroom.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Grid.hpp"

GameWrapper::GameWrapper(void)
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // Can be changed later
    
    int windowDimension = (int)(std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * 0.8);
    // objScale makes objects fit exactly inside 1 grid slot
    this->objScale = (float)windowDimension / (16 * Grid::getGridDimension());

    window = new sf::RenderWindow(sf::VideoMode(windowDimension, windowDimension), "Centipede", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);
    window->setMouseCursorVisible(false);

    // Insert textures into list
    // We need to load here because otherwise the textures don't get created properly
    
    textureList.insert(std::pair<std::string, sf::Texture>("Mushroom", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Bullet", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Body", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Flea", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Head", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Player", sf::Texture()));
    textureList.insert(std::pair<std::string, sf::Texture>("Spider", sf::Texture()));

    textureList.at("Bullet").loadFromFile("assets/CEN_1BLLT.png");
    textureList.at("Body").loadFromFile("assets/CEN_1BODY.png");
    textureList.at("Flea").loadFromFile("assets/CEN_1FLEA.png");
    textureList.at("Head").loadFromFile("assets/CEN_1HEAD.png");
    textureList.at("Player").loadFromFile("assets/CEN_1PLYR.png");
    textureList.at("Mushroom").loadFromFile("assets/CEN_1SHRM.png");
    textureList.at("Spider").loadFromFile("assets/CEN_1SPDR.png");

    // Create player:
    this->player = new Player(this->objScale, Grid::getGridPos(12, 20, *window), textureList.at("Player"));
    // centers the texture over the cursor
    player->setOrigin((float)textureList.at("Player").getSize().x / 2, (float)textureList.at("Player").getSize().y / 2);
    objList.push_back(player);

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
                cur.y = rand() % (int)(Grid::getGridDimension() / 1.5);
            }
            if (foundMatch) break;
        }
        used.push_back(cur);
        objList.push_back(new Mushroom(objScale, sf::Vector2f(Grid::getGridPos(cur.x, cur.y, *window)), textureList.at("Mushroom"), 4));
    }
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
    int counter = 0, round = 1;
    bool isRoundSetup = true;

    while (window->isOpen())
    {
        // Maybe change this to a multi-frame thing later
        if (isRoundSetup)
        {
            startRound(round);
            isRoundSetup = false;
        }
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

        // Real game loop:
        for (int i = 0; i < objList.size(); i++)
        {
            objList[i]->update(*window); // movement
            // collision loop here
        }
        
        std::cout << "Player position: " << objList[0]->getPosition().x << ", " << objList[0]->getPosition().y << "\n";

        window->clear();

        // Draw loop: 
        for (int i = 0; i < objList.size(); i++)
        {
            window->draw(*(objList[i]));
        }

        window->draw(*player);

        window->display();
        counter++;
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

    // set player position to center
    player->setPosition(Grid::getGridPos(12, 20, *window));
}