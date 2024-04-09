//
// Created by ofarukdogancay on 4/9/24.
//

#ifndef GESTALT_EVENTBUS_H
#define GESTALT_EVENTBUS_H

#include <string>
#include <functional>
#include <queue>
#include <memory>

namespace Gestalt {

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus,
        AppTick, AppRender,
        KeyPressed, KeyReleased, KeyRepeated,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum class EventCategory {
        None = 0,
        Application,
        Window,
        Input,
        Keyboard,
        Mouse,
        MouseButton
    };

    class Event {
    public:
        virtual ~Event() = default;

        virtual EventType GetEventType() const = 0;

        virtual const char *GetName() const = 0;

        virtual std::string ToString() const { return GetName(); }

        virtual bool IsInCategory(EventCategory category);
    };


    class EventBus {
    private:
        static std::vector<std::pair<EventType, std::function<void(Event &)>>> s_EventCallbacks;
        static std::vector<std::pair<EventCategory, std::function<void(Event &)>>> s_EventCategoryCallbacks;
        static std::queue<std::unique_ptr<Event>> s_EventQueue;

    public:
        static void Subscribe(EventType type, const std::function<void(Event &)> &callback);

        static void Unsubscribe(EventType type, const std::function<void(Event &)> &callback);

        static void SubscribeCategory(EventCategory category, const std::function<void(Event &)> &callback);

        static void UnsubscribeCategory(EventCategory category, const std::function<void(Event &)> &callback);

        static void Publish(Event *event);

        static void PollEvents();

        static void Shutdown();

    };


}


#endif //GESTALT_EVENTBUS_H
