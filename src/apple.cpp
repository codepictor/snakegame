#include "apple.h"



Apple::Apple(const int block_size)
    : block_size_(block_size)
{
    shape_.setRadius(static_cast<float>(block_size) / 2.0f);
    shape_.setFillColor(sf::Color::Red);
}



sf::Vector2i Apple::GetPosition() const
{
    return position_;
}



void Apple::Spawn(const sf::Vector2i& new_position)
{
    position_ = new_position;
}



void Apple::Update(const float dt)
{
}



void Apple::Render(sf::RenderWindow& window)
{
    shape_.setPosition(sf::Vector2f(
        position_.x * block_size_,
        position_.y * block_size_
    ));
    //shape_.setFillColor
    window.draw(shape_);
}

