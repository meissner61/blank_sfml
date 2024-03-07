#pragma once


#include "SFML/Graphics.hpp"


struct SnakeSegment
{
    SnakeSegment(int x, int y) : position(x,y){}
    sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction
{
    None,
    Up,
    Down,
    Left,
    Right
};

class Snake
{

public:
    Snake(int l_blockSize);
    //Snake(const Snake&) = delete; //copy constructor delete for testing VScode class constructor parameter hints
    ~Snake();

    //Helper Functions
    void SetDirection(Direction l_dir);
    Direction GetDirection();
    int GetSpeed();
    //Book return default position of 1,1 but that might be a bug...
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();
    void Lose();
    void ToggleLost();

    void Extend();
    void Reset();

    void Move();
    void Tick();
    void Cut(int segments);
    void Render(sf::RenderWindow& window);

private:

    void CheckCollision();
    SnakeContainer m_snakeBody; //segment vector //std::vector<SnakeSegment>
    int m_size;
    Direction m_dir;
    int m_speed;
    int m_lives;
    int m_score;
    bool m_lost;
    sf::RectangleShape m_bodyRect;


};