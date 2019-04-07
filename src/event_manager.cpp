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



bool EventManager::Unsubscribe(const SubscriberID subscriber_id)
{
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
        //std::cerr << "Calling callback" << std::endl;
        subscriber.callback(event);
    }
}



void EventManager::Update() const
{

}

