#pragma once

#include <vector>

#include <SFML/Graphics.hpp>



class EventManager;



class Snake
{
public:
    struct Segment
    {
        sf::Vector2i position;
        sf::RectangleShape shape;
        sf::Color color;
    };


    enum class Direction
    {
        None,
        Up,
        Right,
        Down,
        Left
    };


public:
    explicit Snake(EventManager& event_manager);
    virtual ~Snake() = default;

    void Spawn(const sf::Vector2i& new_position);
    void Grow();
    bool CheckSelfCollision() const;
    
    Direction GetDirection() const;
    void SetDirection(const Direction new_direction);

    sf::Vector2i GetHeadPosition() const;
    const std::vector<Segment>& GetBody() const;

    int GetSpeed() const;
    void IncreaseSpeed(const int delta);
    int GetLivesNumber() const;
    void DecreaseLivesNumber();
    int GetScore() const;
    void IncreaseScore(const int delta);
    
    void HandleEvent(const sf::Event& event);
    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    float time_since_last_move_ = 0.0f;
    void MoveByOneCell();

    std::vector<Segment> body_;
    Direction direction_ = Direction::None;
    int speed_ = 0;  // cells per second
    int lives_ = 3;
    int score_ = 0;
};

