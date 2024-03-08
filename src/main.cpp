#include <iostream>
#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "World.h"


using namespace std;

void WindowCollision(sf::Sprite& ball, sf::Vector2f& increment, sf::Vector2u& ball_size, sf::RenderWindow& window);


    World world(sf::Vector2u(800,600));
    Snake snek(16);

    // sf::Clock clok;
    // sf::Time tim = clok.getElapsedTime();

    // float m_elapsed = tim.asSeconds();






int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800,600), "First Window!!!");

    sf::Texture ballTexture;
    ballTexture.loadFromFile("../data/ball.png");
    sf::Sprite ball(ballTexture);
    sf::Vector2u ball_size = ballTexture.getSize();

    //ballTexture.getSize().x

    window.setFramerateLimit(30);
    //window.setVerticalSyncEnabled(true);

    //ball.setOrigin(size.x / 2, size.y / 2);

    sf::Vector2f increment(10.0f, 10.0f);

    // increment.x += 0.05f;
    // increment.y += 0.05f;

    ball.setPosition(0,0);

    ball.getTextureRect();
    
    cout << "Windows size.x(): " << window.getSize().x << "\n";
    cout << "Windows size.y(): " << window.getSize().y << "\n";

    cout << "size.x: " << ball_size.x << "\n";

    //ball.setColor(sf::Color(40,20,255,255));

    sf::Clock clock;

    sf::Time elapsed = clock.getElapsedTime();

    

    while(window.isOpen())
    {
        sf::Event sfEvent;
        while(window.pollEvent(sfEvent))
        {
            if(sfEvent.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sfEvent.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea((float)0, (float)0, (float)sfEvent.size.width, (float)sfEvent.size.height);
                window.setView(sf::View(visibleArea));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snek.GetDirection() != Direction::Down)
            {
                snek.SetDirection(Direction::Up);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snek.GetDirection() != Direction::Up)
            {
                snek.SetDirection(Direction::Down);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snek.GetDirection() != Direction::Right)
            {
                snek.SetDirection(Direction::Left);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snek.GetDirection() != Direction::Left)
            {
                snek.SetDirection(Direction::Right);
            }
        }

        float timestep = 1.0f / snek.GetSpeed();

        snek.Tick();
        world.Update(snek);
        if(snek.HasLost())
        {
            snek.Reset();
        }

        std::cout << "Seconds since start: " << elapsed.asMicroseconds() <<  std::endl;


        // if(m_elapsed >= timestep)
        // {
        //     snek.Tick();
        //     world.Update(snek);
        //     m_elapsed -= timestep;
        //     if(snek.HasLost())
        //     {
        //         snek.Reset();
        //     }
        // }


        WindowCollision(ball, increment, ball_size, window);

        //puts("TEST");

        world.Render(window);
        snek.Render(window);

        ball.setPosition(ball.getPosition() + increment);

        window.draw(ball);
        window.display();
        window.clear(sf::Color(50,50,50,255));
    }

}

void WindowCollision(sf::Sprite& ball, sf::Vector2f& increment, sf::Vector2u& ball_size, sf::RenderWindow& window)
{
        if((ball.getPosition().x + (ball_size.x)) > window.getSize().x || 
        ball.getPosition().x  < 0)
        {
            increment.x *= -1;
        }

        if((ball.getPosition().y + (ball_size.y)) > window.getSize().y || 
        ball.getPosition().y < 0)
        {
            increment.y *= -1;
        }
}