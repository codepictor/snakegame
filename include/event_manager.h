#pragma once

#include <vector>
#include <unordered_map>
#include <functional>

#include <SFML/Graphics.hpp>



class EventManager
{
public:
    EventManager() = default;
    virtual ~EventManager() = default;

    using SubscriberID = int;

    SubscriberID Subscribe(
        const sf::Event::EventType event_type,
        std::function<void(const sf::Event&)> callback
    );
    bool Unsubscribe(
        const sf::Event::EventType event_type,
        const SubscriberID subscriber_id
    );

    void HandleEvent(const sf::Event& event);
    void Update() const;


private:
    struct Subscriber
    {
        SubscriberID subscriber_id;
        std::function<void(const sf::Event&)> callback;
    };

    SubscriberID next_subscriber_id_ = 0;

    std::unordered_map<
        sf::Event::EventType, std::vector<Subscriber>
    > subscribers_;
};

