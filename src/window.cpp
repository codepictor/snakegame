#include "window.h"



Window::Window(const std::string& title, const sf::Vector2i& sizes)
{
    default_title_ = title;
    default_sizes_ = sizes;

    Create();
}



Window::~Window()
{
    Destroy();
}



bool Window::CheckIsClosed() const
{
    return is_closed_;
}



void Window::Update()
{
    sf::Event event;
    while (window_.pollEvent(event))
    {
        event_manager_.HandleEvent(event);
    }
}



void Window::BeginDraw()
{
    window_.clear(sf::Color::Black);
}



void Window::DrawWorld(World& world)
{
    world.Render(window_);
}



void Window::EndDraw()
{
    window_.display();
}



void Window::Create()
{
    window_.create(
        sf::VideoMode(default_sizes_.x, default_sizes_.y),
        default_title_,
        sf::Style::Titlebar | sf::Style::Close
    );

    event_manager_.Subscribe(
        sf::Event::Closed,  // type of event
        std::bind(&Window::Destroy, this)  // callback
    );
}



void Window::Destroy()
{
    if (!is_closed_)
    {
        window_.close();
        is_closed_ = true;
    }
}


