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
    explicit Snake(const int block_size);
    virtual ~Snake() = default;

    void Spawn(const sf::Vector2i& new_position);
    void Grow();
    bool CheckSelfCollision() const;
    
    Direction GetDirection() const;
    void SetDirection(const Direction new_direction);

    sf::Vector2i GetHeadPosition() const;
    int GetSpeed() const;
    int GetLivesNumber() const;
    void DecreaseLivesNumber();
    int GetScore() const;
    void IncreaseScore(const int delta);
    
    void Update(const float dt);
    void Render(sf::RenderWindow& window);


private:
    void Move();

    std::vector<Segment> body_;
    int block_size_ = 0;
    Direction direction_ = Direction::None;
    int speed_ = 0;
    int lives_ = 3;
    int score_ = 0;
    bool is_lost_ = false;
};
