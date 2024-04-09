//
// Created by ofarukdogancay on 4/9/24.
//

#ifndef GESTALT_WINDOWEVENT_H
#define GESTALT_WINDOWEVENT_H

#include "EventBus.h"

namespace Gestalt {
    class WindowEvent : public Event {

    public:

        virtual ~WindowEvent() = default;

        bool IsInCategory(EventCategory category) override { return category == EventCategory::Window; }

    };

    class WindowCloseEvent : public WindowEvent {

    public:

        EventType GetEventType() const override { return EventType::WindowClose; }

        const char *GetName() const override { return "WindowCloseEvent"; }
    };

    class WindowResizeEvent : public WindowEvent {

    private:
        uint32_t width, height;

    public:

        WindowResizeEvent(uint32_t width, uint32_t height) : width(width), height(height) {};

        EventType GetEventType() const override { return EventType::WindowResize; }

        const char *GetName() const override { return "WindowResizeEvent"; }

        uint32_t GetWidth() const { return width; }

        uint32_t GetHeight() const { return height; }

    };

    class WindowFocusEvent : public WindowEvent {

    public:

        EventType GetEventType() const override { return EventType::WindowFocus; }

        const char *GetName() const override { return "WindowFocusEvent"; }

    };

    class WindowLostFocusEvent : public WindowEvent {

    public:

        EventType GetEventType() const override { return EventType::WindowLostFocus; }

        const char *GetName() const override { return "WindowLostFocusEvent"; }

    };
}

#endif //GESTALT_WINDOWEVENT_H
