#include "Game.h"

Game::Game() : m_window("Win Title", {800,600})
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
}

void Game::Update()
{
    m_window.Update();
}

void Game::Render()
{
    m_window.BeginDraw();
    //m_window.Draw();
    m_window.EndDraw();
}
