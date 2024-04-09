//
// Created by ofarukdogancay on 4/9/24.
//

#include "EventBus.h"

void EventBus::Subscribe(EventType type, const std::function<void(Event &)>& callback) {
    s_EventCallbacks.emplace_back(type, callback);
}

void EventBus::Unsubscribe(EventType type, const std::function<void(Event &)>& callback) {
    for (auto it = s_EventCallbacks.begin(); it != s_EventCallbacks.end(); it++) {
        if (it->first == type && it->second.target_type() == callback.target_type()) {
            s_EventCallbacks.erase(it);
            return;
        }
    }
}

void EventBus::SubscribeCategory(EventCategory category, const std::function<void(Event &)>& callback) {
    s_EventCategoryCallbacks.emplace_back(category, callback);
}

void EventBus::UnsubscribeCategory(EventCategory category, const std::function<void(Event &)>& callback) {
    for (auto it = s_EventCategoryCallbacks.begin(); it != s_EventCategoryCallbacks.end(); it++) {
        if (it->first == category && it->second.target_type() == callback.target_type()) {
            s_EventCategoryCallbacks.erase(it);
            return;
        }
    }
}

void EventBus::Publish(Event *event) {
    s_EventQueue.push(std::unique_ptr<Event>(event));
}

void EventBus::PollEvents() {

    while (!s_EventQueue.empty()) {
        auto &event = s_EventQueue.front();

        for (auto &callback : s_EventCallbacks) {
            if (callback.first == event->GetEventType()) {
                callback.second(*event);
            }
        }

        for (auto &callback : s_EventCategoryCallbacks) {
            if (event->IsInCategory(callback.first)) {
                callback.second(*event);
            }
        }

        s_EventQueue.pop();
    }

}
