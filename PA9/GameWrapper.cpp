#include "GameWrapper.hpp"
#include "Mushroom.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

GameWrapper::GameWrapper(void)
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 5; // Can be changed later
    
    int windowDimension = (int)(std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * 0.8);

    window = new sf::RenderWindow(sf::VideoMode(windowDimension, windowDimension), "Centipede", sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);
}

GameWrapper::~GameWrapper()
{
    delete window;
    while (!objList.empty())
    {
        objList.pop_back(); // automatically calls destructor
    }
}

void GameWrapper::run(void)
{
    sf::Texture texture1;
    texture1.loadFromFile("assets/CEN_1SHRM.png");

    // bullet stuff 
    Bullet bullets = Bullet(5, sf::Vector2f(300, 300), texture1, 4);
    bullets.setOrigin((float)texture1.getSize().x / 2, (float)texture1.getSize().y / 2);
    //sf::Texture bulletTexture;
    //bulletTexture.loadFromFile();

    Mushroom m1 = Mushroom(5, sf::Vector2f(300, 300), texture1, 4);

    // p1 stuff
    Player p1 = Player(5, sf::Vector2f(300, 300), texture1, 4); // temporarily copied mushroom texture
    p1.setOrigin((float)texture1.getSize().x / 2, (float)texture1.getSize().y / 2); // centers the texture over the curser 
    window->setMouseCursorVisible(false); // hides the mouse curser

    int counter = 0;

    sf::Clock clock;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) // pollEvent uses event as a return param for the internal event queue
        {
            if (event.type == sf::Event::Closed) window->close();

            if (event.type == sf::Event::MouseButtonPressed) // we can check if its a left click or right click later
            {
                if (p1.canShoot())
                {
                    // Create a new bullet and add it to list of GameObjects
                }
            }
        }
        p1.move(*window); // reads mouse position - window needs to be passed in so mouse position is relative to the window rather than the computer screen
        // in the event the mouse is clicked a fire function needs to be done 

        if (counter >= 60 && !m1.isDead())
        {
            std::cout << "hit\n";
            m1.hit();
            counter = 0;
        }

        window->clear();

        //Makes the mushroom slide across the screen
        if (counter % 10 == 0)
        {
            m1.glideTo((float)counter, (float)counter);
        }

        // draw function 
        m1.update();
        window->draw(m1);
        window->draw(p1);
        window->draw(bullets);
        window->display();


        counter++;
    }
}
void GameWrapper::startRound(unsigned int round)
{
    // Do palette swaps, generate mushrooms, create a new centipede object, etc.
    // Because this takes multiple frames, maybe need to make some sort of status enum in gamewrapper
    // that allows us to pause for animations?
}