
#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "EventManager.h"

class Window
{


public:
    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    bool IsFullscreen();
    bool isFocused();
   
    sf::Vector2u GetWindowSize();
    sf::RenderWindow* GetRenderWindow();


    EventManager* GetEventManager();


    void ToggleFullScreen(EventDetails* l_details);
    void Close(EventDetails* l_details = nullptr);

    void Draw(sf::Drawable& drawable);
    

private:
    void Setup(const std::string& title, const sf::Vector2u size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;

    EventManager m_eventManager;
    bool m_isFocused;

};