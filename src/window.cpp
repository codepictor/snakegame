#include "window.h"



Window::Window(const std::string& title, const sf::Vector2u& size)
{
    is_closed_ = false;

    default_title_ = title;
    default_size_ = size;

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
        if (event.type == sf::Event::Closed)
        {
            is_closed_ = true;
        }
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



sf::Vector2u Window::GetWindowSize()
{
    return window_.getSize();
}



void Window::Create()
{
    window_.create(
        sf::VideoMode(default_size_.x, default_size_.y),
        default_title_
    );
}



void Window::Destroy()
{
    window_.close();
}

