#include "wall.h"



Wall::Wall(const int block_size)
    : block_size_(block_size)
{
    shape_.setFillColor(sf::Color::Blue);
}



void Wall::Update(const float dt)
{
}



void Wall::Render(sf::RenderWindow& window)
{
    window.draw(shape_);
}

