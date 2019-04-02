#pragma once

#include <SFML/Graphics.hpp>



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
    Snake() = default;
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
    
    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    float time_since_last_move_ = 0.0f;
    void Move();

    std::vector<Segment> body_;
    Direction direction_ = Direction::None;
    int speed_ = 5;  // cells per second
    int lives_ = 3;
    int score_ = 0;
};

