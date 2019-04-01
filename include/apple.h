#pragma once

#include <SFML/Graphics.hpp>



class Apple
{
public:
    explicit Apple(const int block_size);
    virtual ~Apple() = default;

    sf::Vector2i GetPosition() const;

    void Spawn(const sf::Vector2i& new_position);

    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    int block_size_;

    sf::Vector2i position_;
    sf::CircleShape shape_;
};

