#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>



class MessageBox
{
public:
    MessageBox(
        const sf::Vector2i& position, const sf::Vector2i& sizes,
        const int char_size
    );
    virtual ~MessageBox() = default;

    void Setup(
        const sf::Vector2i& position, const sf::Vector2i& sizes,
        const int char_size
    );
    void Add(const std::string& new_message);
    void Clear();

    void Update();
    void Render(sf::RenderWindow& window);


private:
    std::vector<std::string> messages_;
    int max_strings_visible_;

    sf::RectangleShape background_;
    sf::Font font_;
    sf::Text string_;
};

