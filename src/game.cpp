#include "game.h"

#include <iostream>

Game::Game()
    : main_window_("Snake", sf::Vector2u(800, 600))
    , world_(main_window_.GetWindowSize(), 16)
{
}



void Game::Run()
{
    const sf::Time time_per_frame = sf::seconds(1.0f / 15.0f);
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
    world_.HandleInput();
}



void Game::Update(const float dt)
{
    std::cerr << "### " << world_.snake_.GetLivesNumber() << std::endl;
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

