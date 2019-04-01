#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "world.h"



class Window
{
public:
    Window(const std::string& title, const sf::Vector2u& size);
    virtual ~Window();

    sf::Vector2u GetWindowSize();
    bool CheckIsClosed() const;

    void Update();
    void BeginDraw();
    void DrawWorld(World& world);
    void EndDraw();
    

private:
    void Create();
    void Destroy();

    bool is_closed_ = false;

    sf::RenderWindow window_;
    std::string default_title_;
    sf::Vector2u default_size_;
};

