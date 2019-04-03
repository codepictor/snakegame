#include <ctime>

#include "game.h"



extern const int BLOCK_SIZE = 20;
extern const sf::Vector2i WORLD_SIZES(50, 30);



Game::Game()
    : main_window_("Snake", WORLD_SIZES * BLOCK_SIZE)
    , world_(WORLD_SIZES)
{
    // for generating random positions of apple and snake
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}



void Game::Run()
{
    const float updates_per_frame = 60.0f;
    const sf::Time time_per_frame = sf::seconds(1.0f / updates_per_frame);

    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;

    while (true)
    {
        time_since_last_update += clock.restart();

        while (time_since_last_update > time_per_frame)
        {
            time_since_last_update -= time_per_frame;
            HandleInput();
            Update(time_per_frame.asSeconds());
        }

        Render();

        if (main_window_.CheckIsClosed())
        {
            return;
        }
    }
}



void Game::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        world_.snake_.GetDirection() != Snake::Direction::Down)
    {
        world_.snake_.SetDirection(Snake::Direction::Up);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        world_.snake_.GetDirection() != Snake::Direction::Left)
    {
        world_.snake_.SetDirection(Snake::Direction::Right);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        world_.snake_.GetDirection() != Snake::Direction::Up)
    {
        world_.snake_.SetDirection(Snake::Direction::Down);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        world_.snake_.GetDirection() != Snake::Direction::Right)
    {
        world_.snake_.SetDirection(Snake::Direction::Left);
    }
}



void Game::Update(const float dt)
{
    //std::cerr << "### " << world_.snake_.GetLivesNumber() << std::endl;
    if (world_.snake_.GetLivesNumber() <= 0)
    {
        //std::cerr << "Lose\n";
    }

    main_window_.Update();
    world_.Update(dt);
}



void Game::Render()
{
    main_window_.BeginDraw();

    main_window_.DrawWorld(world_);

    main_window_.EndDraw();
}

