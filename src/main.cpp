#include <iostream>

#include "Game.h"

using namespace std;

Game game;

int main()
{

    while(!game.GetWindow()->IsDone())
    {
        game.Input();
        game.Update();
        game.Render();
        game.RestartClock();
    }

    


    sf::Clock clock;

    sf::Time elapsed = clock.getElapsedTime();

    
    return 0;
}

