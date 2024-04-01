
#pragma once

#include "Window.h"


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




private:

    Window m_window;
    


};