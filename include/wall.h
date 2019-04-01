#pragma once

#include <SFML/Graphics.hpp>



class Wall
{
public:
    explicit Wall(const int block_size);
    virtual ~Wall() = default;

    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    int block_size_;

    sf::RectangleShape shape_;
};

