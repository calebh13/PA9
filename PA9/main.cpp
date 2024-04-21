#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Mushroom.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

int main()
{
    // all of this could go in an init variables funciton in game object
    sf::ContextSettings settings;
    settings.antialiasingLevel = 5; // Can be changed later
    
    int windowDimension = (int)(std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * 0.8);

    sf::RenderWindow window(sf::VideoMode(windowDimension, windowDimension), "Centipede", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Texture texture1;
    texture1.loadFromFile("assets/CEN_1SHRM.png");


    // bullet stuff 
    std::vector<Bullet> bullets;
    //sf::Texture bulletTexture;
    //bulletTexture.loadFromFile();

    Mushroom m1 = Mushroom(sf::Vector2f(5, 5), sf::Vector2f(300, 300), texture1, 4);
   
    // p1 stuff
    Player p1 = Player(sf::Vector2f(5, 5), sf::Vector2f(300, 300), texture1, 4); // temporarliy copied mushroom texture
    p1.setOrigin(texture1.getSize().x/2, texture1.getSize().y/2); // centers the texture over the curser 
    window.setMouseCursorVisible(false); // hides the mouse curser

    int counter = 0;

    sf::Clock clock;

    //bool pressed = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) // pollEvent uses event as a return param for the internal event queue
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) // we can check if its a left click or right click later
            {
                //pressed = true;
                Bullet currBullet(sf::Vector2f(5, 5), sf::Vector2f(300, 300), texture1, 4);
                currBullet.setOrigin(texture1.getSize().x / 2, texture1.getSize().y / 2);
                p1.setBulletPosition(currBullet);
                bullets.push_back(currBullet);
            }
        }
        p1.move(window); // reads mouse position - window needs to be passed in so mouse position is relative to the window rather than the computer screen
        // in the event the mouse is clicked a fire function needs to be done

        for (int i = 0; i < bullets.size(); ++i)
        {
            if (bullets[i].getPosition().y > 0)
            {
                bullets[i].shoot();
            }
            else
            {
                bullets.erase(bullets.begin() + i);
                --i;
            }
        }
  

        if (counter >= 60 && !m1.isDead())
        {
            std::cout << "hit\n";
            m1.hit();
            counter = 0;
        }

        window.clear();

        //Makes the mushroom slide across the screen
        if (counter % 10 == 0)
        {
            m1.glideTo((float)counter, (float)counter);
        }

        // draw function 
        m1.update();
        window.draw(m1);
        window.draw(p1);

        for (int i = 0; i < bullets.size(); ++i)
        {
            window.draw(bullets[i]);
        }

        window.display();


        counter++;

    }
    return 0;
}