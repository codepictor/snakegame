#pragma once

#include <SFML/Graphics.hpp>



class EventManager;



class Apple
{
public:
    explicit Apple(EventManager& event_manager);
    virtual ~Apple() = default;

    sf::Vector2i GetPosition() const;

    void Spawn(const sf::Vector2i& new_position);

    void HandleEvent(const sf::Event& event);
    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    sf::Vector2i position_;
    sf::CircleShape shape_;
};

