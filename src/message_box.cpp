#include "message_box.h"



MessageBox::MessageBox(
    const sf::Vector2i& position, const sf::Vector2i& sizes,
    const int char_size)
{
    Setup(position, sizes, char_size);
}



void MessageBox::Setup(
    const sf::Vector2i& position, const sf::Vector2i& sizes,
    const int char_size)
{
    background_.setPosition(
        static_cast<float>(position.x),
        static_cast<float>(position.y)
    );
    background_.setSize(sf::Vector2f(
        static_cast<float>(sizes.x),
        static_cast<float>(sizes.y)
    ));
    background_.setFillColor(sf::Color(32, 32, 32));

}



void MessageBox::Add(const std::string& new_message)
{
    messages_.push_back(new_message);

    // erase
}



void MessageBox::Clear()
{
    messages_.clear();
}



void MessageBox::Update()
{
}



void MessageBox::Render(sf::RenderWindow& window)
{
    // to one big string
    window.draw(background_);
}

