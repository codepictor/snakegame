#include <ctime>

#include "game.h"



extern const int BLOCK_SIZE = 18;  // in pixels
extern const sf::Vector2i WORLD_SIZES(50, 27);  // in blocks
extern const sf::Vector2i MESSAGE_BOX_SIZES(WORLD_SIZES.x * BLOCK_SIZE, 80);  // in pixels



Game::Game()
    : main_window_(
        "Snake",
        WORLD_SIZES * BLOCK_SIZE + sf::Vector2i(0, MESSAGE_BOX_SIZES.y)
    )
    , world_(WORLD_SIZES, main_window_.GetEventManager())
    , message_box_(
        sf::Vector2i(0, WORLD_SIZES.y * BLOCK_SIZE),  // position (in pixels)
        MESSAGE_BOX_SIZES,  // sizes (in pixels)
        8  // char_size
    )
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
    message_box_.Update();
}



void Game::Render()
{
    main_window_.BeginDraw();

    main_window_.DrawWorld(world_);
    main_window_.DrawMessageBox(message_box_);

    main_window_.EndDraw();
}

