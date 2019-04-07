#include "event_manager.h"



EventManager::SubscriberID EventManager::Subscribe(
    const sf::Event::EventType event_type,
    std::function<void(const sf::Event&)> callback)
{
    const SubscriberID subscriber_id = next_subscriber_id_;
    subscribers_[event_type].push_back(Subscriber{
        subscriber_id,
        callback
    });

    next_subscriber_id_++;
    return subscriber_id;
}



bool EventManager::Unsubscribe(
    const sf::Event::EventType event_type,
    const SubscriberID subscriber_id)
{
    if (subscribers_.count(event_type) == 0)
    {
        return false;
    }

    std::vector<Subscriber>& event_subscribers = subscribers_.at(event_type);
    for (auto it = event_subscribers.begin();
        it != event_subscribers.end();
        it++)
    {
        if (it->subscriber_id == subscriber_id)
        {
            event_subscribers.erase(it);
            return true;
        }
    }

    return false;
}



void EventManager::HandleEvent(const sf::Event& event)
{
    if (subscribers_.count(event.type) == 0)
    {
        return;
    }

    for (const Subscriber& subscriber : subscribers_.at(event.type))
    {
        subscriber.callback(event);
    }
}



void EventManager::Update() const
{

}

