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
    explicit World(const sf::Vector2i& window_sizes);
    virtual ~World() = default;

    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    void HandleCollisions();
    sf::Vector2i FindRandomFreeCell() const;

    sf::Vector2i world_sizes_;

    Snake snake_;
    Apple apple_;
    std::vector<Wall> walls_;
};

