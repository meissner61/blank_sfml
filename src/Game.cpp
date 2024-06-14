#include "Game.h"

Game::Game() : m_window("Input Chapter", {800,600}), m_world({800,600}), m_snek(16)
{
    m_clock.restart();

    m_elapsed = 0.0f;

    m_textbox.Setup(5,14,350,sf::Vector2f(225,0));
    m_textbox.Add("Test");
    m_textbox.Add("Test");
    m_textbox.Add("Test");

}

Game::~Game()
{
}

void Game::Setup()
{
}

void Game::Run()
{
}

void Game::Input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snek.GetDirection() != Direction::Down)
    {
        m_snek.SetDirection(Direction::Up);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snek.GetDirection() != Direction::Up)
    {
        m_snek.SetDirection(Direction::Down);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snek.GetDirection() != Direction::Right)
    {
        m_snek.SetDirection(Direction::Left);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snek.GetDirection() != Direction::Left)
    {
        m_snek.SetDirection(Direction::Right);
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_textbox.Add("W Pressed");
    }
}

void Game::Update()
{
    m_window.Update();
    

    float timestep = 1.0f / m_snek.GetSpeed();
//MINE
    // m_snek.Tick();
    // m_world.Update(m_snek);
    // if(m_snek.HasLost())
    // {
    //     m_snek.Reset();
    // }
//  END OF MINE

    if(m_elapsed >= timestep)
    {
        m_snek.Tick();
        m_world.Update(m_snek);
        m_elapsed -= timestep;
        if(m_snek.HasLost())
        {
            m_snek.Reset();
        }
    }
}

void Game::Render()
{
    m_window.BeginDraw();

    m_world.Render(*m_window.GetRenderWindow());
    m_snek.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow());
    //m_window.Draw();
    m_window.EndDraw();
}

void Game::RestartClock()
{
    m_elapsed += m_clock.restart().asSeconds();
}

Window *Game::GetWindow()
{
    return &m_window;
}
