#include "Window.h"

Window::Window()
{
    Setup("Window", sf::Vector2u(800,600));
}

Window::Window(const std::string &title, const sf::Vector2u &size)
{
    Setup(title, size);
}

Window::~Window()
{
    Destroy();
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
    m_window.display();
}

void Window::Update()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::LostFocus)
        {
            m_isFocused = false;
            m_eventManager.SetFocus(false);
            puts("Lost Focus");
        }
        else if(event.type == sf::Event::GainedFocus)
        {
            m_isFocused = true;
            m_eventManager.SetFocus(true);
            puts("Gained Focus");
        }
        // else if(event.type == sf::Event::Closed)
        // {
        //     m_isDone = true;
        // }
        // else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
        // {
        //     //ToggleFullScreen();
        // }
        m_eventManager.HandleEvent(event);
    }
    m_eventManager.Update();
}

bool Window::IsDone()
{
    return m_isDone;
}

bool Window::IsFullscreen()
{
    return m_isFullscreen;
}

bool Window::isFocused()
{
    return m_isFocused;
}

sf::Vector2u Window::GetWindowSize()
{
    return m_windowSize;
}

sf::RenderWindow *Window::GetRenderWindow()
{
    return &m_window;
}

EventManager *Window::GetEventManager()
{
    return &m_eventManager;
}

void Window::ToggleFullScreen(EventDetails* l_details)
{
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::Close(EventDetails *l_details)
{
    m_isDone = true;
}

void Window::Draw(sf::Drawable &drawable)
{
    drawable;
}

void Window::Setup(const std::string &title, const sf::Vector2u size)
{
    m_windowTitle = title;
    m_windowSize = size;
    m_isFullscreen = false;
    m_isDone = false;

    m_isFocused = true;
    m_eventManager.AddCallback("Fullscreen_toggle", &Window::ToggleFullScreen, this);
    m_eventManager.AddCallback("Window_close", &Window::Close, this);

    Create();
}

void Window::Destroy()
{
    m_window.close();
}

void Window::Create()
{
    sf::Uint32 style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}
