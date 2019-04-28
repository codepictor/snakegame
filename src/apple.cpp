#include <cassert>

#include "apple.h"
#include "event_manager.h"



extern const int BLOCK_SIZE;
extern const sf::Vector2i WORLD_SIZES;



Apple::Apple(EventManager& event_manager)
{
}



void Apple::Create(const sf::Vector2i& new_position)
{
    assert(0 <= new_position.x && new_position.x < WORLD_SIZES.x);
    assert(0 <= new_position.y && new_position.y < WORLD_SIZES.y);

    Spawn(new_position);
}



void Apple::Spawn(const sf::Vector2i& new_position)
{
    assert(0 <= new_position.x && new_position.x < WORLD_SIZES.x);
    assert(0 <= new_position.y && new_position.y < WORLD_SIZES.y);

    position_ = new_position;
}



sf::Vector2i Apple::GetPosition() const
{
    return position_;
}



void Apple::HandleEvent(const sf::Event& event)
{
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
