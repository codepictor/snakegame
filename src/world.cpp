#include "world.h"

#include <iostream>



extern const sf::Vector2i WORLD_SIZES;



World::World(const sf::Vector2i& world_size)
    : world_sizes_(WORLD_SIZES)
{
    apple_.Spawn(sf::Vector2i(4, 4));
    snake_.Spawn(sf::Vector2i(7, 7));

    // number of walls is equal to 4 (up, right, down and left walls)
    walls_.push_back(Wall(
        {0, 0},
        {world_sizes_.x - 1, 0}
    ));
    walls_.push_back(Wall(
        {0, 0},
        {0, world_sizes_.y - 1}
    ));
    walls_.push_back(Wall(
        {0, world_sizes_.y - 1},
        {world_sizes_.x - 1, world_sizes_.y - 1}
    ));
    walls_.push_back(Wall(
        {world_sizes_.x - 1, 0},
        {world_sizes_.x - 1, world_sizes_.y - 1}
    ));
}



void World::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        snake_.GetDirection() != Snake::Direction::Down)
    {
        snake_.SetDirection(Snake::Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        snake_.GetDirection() != Snake::Direction::Left)
    {
        snake_.SetDirection(Snake::Direction::Right);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        snake_.GetDirection() != Snake::Direction::Up)
    {
        snake_.SetDirection(Snake::Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        snake_.GetDirection() != Snake::Direction::Right)
    {
        snake_.SetDirection(Snake::Direction::Left);
    }
}



void World::Update(const float dt)
{
    HandleCollisions();

    apple_.Update(dt);
    snake_.Update(dt);
    for (size_t i = 0; i < walls_.size(); i++)
    {
        walls_[i].Update(dt);
    }
}



void World::Render(sf::RenderWindow& window)
{
    apple_.Render(window);
    snake_.Render(window);

    for (size_t i = 0; i < walls_.size(); i++)
    {
        walls_[i].Render(window);
    }
}



void World::HandleCollisions()
{
    if (snake_.CheckSelfCollision())
    {
        snake_.DecreaseLivesNumber();
    }

    for (size_t i = 0; i < walls_.size(); i++)
    {
        //if (snake_.GetHeadPosition() == walls_[i].)
        // snake_.DecreaseLivesNumber();
    }

    if (snake_.GetHeadPosition() == apple_.GetPosition())
    {
        apple_.Spawn(apple_.GetPosition() + sf::Vector2i(2, 1));
        snake_.Grow();
        snake_.IncreaseScore(10);
    }
}


