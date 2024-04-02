#include "Game.h"

Game::Game() : m_window("Win Title", {800,600}), m_world({800,600}), m_snek(16)
{
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
}

void Game::Update()
{
    m_window.Update();

    float timestep = 1.0f / m_snek.GetSpeed();

    m_snek.Tick();
    m_world.Update(m_snek);
    if(m_snek.HasLost())
    {
        m_snek.Reset();
    }
}

void Game::Render()
{
    m_window.BeginDraw();

    m_world.Render(*m_window.GetRenderWindow());
    m_snek.Render(*m_window.GetRenderWindow());
    //m_window.Draw();
    m_window.EndDraw();
}

Window *Game::GetWindow()
{
    return &m_window;
}
