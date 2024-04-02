
#pragma once

#include "Window.h"
#include "Snake.h"
#include "World.h"


class Game
{


public:

    Game();
    ~Game();

    void Setup();

    void Run();

    void Input();
    void Update();
    void Render();

    Window* GetWindow();




private:

    Window m_window;
    
    World m_world;//(sf::Vector2u(800,600));
    Snake m_snek;//(16);


};