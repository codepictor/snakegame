#include <cmath>
#include <utility>
#include <cassert>

#include "snake.h"



extern const int BLOCK_SIZE;



void Snake::Spawn(const sf::Vector2i& new_position)
{
    body_.clear();
    body_.push_back(Segment{new_position});

    direction_ = Direction::None;
    speed_ = 3;
}



Snake::Direction Snake::GetDirection() const
{
    if (body_.size() <= 1)
    {
        return direction_;
    }

    assert(body_.size() >= 2);
    const Segment& head = body_[0];
    const Segment& after_head = body_[1];
    assert(head.position.x == after_head.position.x ||
        head.position.y == after_head.position.y);

    if (head.position.x == after_head.position.x)
    {
        assert(abs(head.position.y - after_head.position.y) == 1);
        return (head.position.y > after_head.position.y) ?
            Direction::Down : Direction::Up;
    }
    else
    {
        assert(abs(head.position.x - after_head.position.x) == 1);
        return (head.position.x > after_head.position.x) ?
            Direction::Right : Direction::Left;
    }

    return Direction::None;
}



void Snake::SetDirection(const Direction new_direction)
{
    direction_ = new_direction;
}



sf::Vector2i Snake::GetHeadPosition() const
{
    return (!body_.empty() ? body_.front().position : sf::Vector2i(-1, -1));
}



const std::vector<Snake::Segment>& Snake::GetBody() const
{
    return body_;
}



int Snake::GetSpeed() const
{
    return speed_;
}



void Snake::IncreaseSpeed(const int delta)
{
    speed_ += delta;
}



int Snake::GetLivesNumber() const
{
    return lives_;
}



void Snake::DecreaseLivesNumber()
{
    lives_--;
}



int Snake::GetScore() const
{
    return score_;
}



void Snake::IncreaseScore(const int delta)
{
    score_ += delta;
}



void Snake::Grow()
{
    assert(!body_.empty());

    Segment new_segment = {sf::Vector2i(0, 0)};
    if (body_.size() == 1)
    {
        const Segment& head = body_.front();
        switch (direction_)
        {
            case Direction::Up:
                new_segment.position = sf::Vector2i(
                    head.position.x,
                    head.position.y + 1
                );
                break;

            case Direction::Right:
                new_segment.position = sf::Vector2i(
                    head.position.x - 1,
                    head.position.y
                );
                break;

            case Direction::Down:
                new_segment.position = sf::Vector2i(
                    head.position.x,
                    head.position.y - 1
                );
                break;

            case Direction::Left:
                new_segment.position = sf::Vector2i(
                    head.position.x + 1,
                    head.position.y
                );
                break;

            default:;  // no direction to grow
        }

        body_.push_back(std::move(new_segment));
        return;
    }

    // now length of the snake >= 2
    assert(body_.size() >= 2);
    const Segment& tail = body_[body_.size() - 1];
    const Segment& before_tail = body_[body_.size() - 2];
    assert(tail.position.x == before_tail.position.x ||
           tail.position.y == before_tail.position.y);

    if (tail.position.x == before_tail.position.x)
    {
        assert(abs(tail.position.y - before_tail.position.y) == 1);
        new_segment.position.x = tail.position.x;
        new_segment.position.y = tail.position.y + (
            tail.position.y > before_tail.position.y ? 1 : -1
        );
    }
    else
    {
        assert(abs(tail.position.x - before_tail.position.x) == 1);
        new_segment.position.y = tail.position.y;
        new_segment.position.x = tail.position.x + (
            tail.position.x > before_tail.position.x ? 1 : -1
        );
    }

    body_.push_back(std::move(new_segment));
}



void Snake::Update(const float dt)
{
    assert(!body_.empty());
    
    time_since_last_move_ += dt;
    const float move_time = 1.0f / static_cast<float>(speed_);
    while (time_since_last_move_ >= move_time)
    {
        if (direction_ != Direction::None)
        {
            MoveByOneCell();
        }
        time_since_last_move_ -= move_time;
    }
}



void Snake::MoveByOneCell()
{
    assert(!body_.empty());

    if (direction_ == Direction::None)
    {
        return;
    }

    for (size_t i = body_.size() - 1; i > 0; i--)
    {
        body_[i].position = body_[i - 1].position;
    }

    Snake::Segment& head = body_.front();
    switch (direction_)
    {
        case Direction::Up:
            head.position.y--;
            break;

        case Direction::Right:
            head.position.x++;
            break;

        case Direction::Down:
            head.position.y++;
            break;

        case Direction::Left:
            head.position.x--;
            break;

        default:;  // no movement should be done
    }
}



bool Snake::CheckSelfCollision() const
{
    const Segment& head = body_.front();

    for (size_t i = 1; i < body_.size(); i++)
    {
        if (head.position == body_[i].position)
        {
            return true;
        }
    }

    return false;
}



void Snake::Render(sf::RenderWindow& window)
{
    if (body_.empty())
    {
        return;
    }

    Segment& head = body_.front();
    head.shape.setFillColor(sf::Color::Yellow);
    head.shape.setPosition(
        static_cast<float>(head.position.x * BLOCK_SIZE),
        static_cast<float>(head.position.y * BLOCK_SIZE)
    );
    head.shape.setSize(sf::Vector2f(
        static_cast<float>(BLOCK_SIZE - 1),
        static_cast<float>(BLOCK_SIZE - 1)
    ));
    window.draw(head.shape);

    for (size_t i = 1; i < body_.size(); i++)
    {
        body_[i].shape.setFillColor(sf::Color::Green);
        body_[i].shape.setPosition(
            static_cast<float>(body_[i].position.x * BLOCK_SIZE),
            static_cast<float>(body_[i].position.y * BLOCK_SIZE)
        );
        body_[i].shape.setSize(sf::Vector2f(
            static_cast<float>(BLOCK_SIZE - 1),
            static_cast<float>(BLOCK_SIZE - 1)
        ));
        window.draw(body_[i].shape);
    }
}


