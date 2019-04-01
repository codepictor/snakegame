#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "snake.h"
#include "apple.h"
#include "wall.h"



class World
{
    friend class Game;

public:
    World(const sf::Vector2u& window_size, const int block_size);
    virtual ~World() = default;

    void HandleInput();
    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    void HandleCollisions();

    sf::Vector2u window_size_;
    const int block_size_;

    Snake snake_;
    Apple apple_;
    std::vector<Wall> walls_;
};

