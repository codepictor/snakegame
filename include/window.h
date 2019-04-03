#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "world.h"



class Window
{
public:
    Window(const std::string& title, const sf::Vector2i& sizes);
    virtual ~Window();

    bool PollEvent(sf::Event& event);

    void HandleInput(const sf::Event& event);
    void Update();
    void BeginDraw();
    void DrawWorld(World& world);
    void EndDraw();
    

private:
    void Create();
    void Destroy();

    sf::RenderWindow window_;
    std::string default_title_;
    sf::Vector2i default_sizes_;
};

