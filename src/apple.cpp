#include "apple.h"



extern const int BLOCK_SIZE;



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
    shape_.setRadius(static_cast<float>(BLOCK_SIZE) / 2.0f);
    shape_.setPosition(sf::Vector2f(
        static_cast<float>(position_.x * BLOCK_SIZE),
        static_cast<float>(position_.y * BLOCK_SIZE)
    ));

    shape_.setFillColor(sf::Color::Red);

    window.draw(shape_);
}
