//
// Created by ofarukdogancay on 4/9/24.
//

#ifndef GESTALT_APPLICATIONEVENT_H
#define GESTALT_APPLICATIONEVENT_H

#include "EventBus.h"

namespace Gestalt {


    class ApplicationEvent : public Event {

    public:

        virtual ~ApplicationEvent() = default;

        bool IsInCategory(EventCategory category) override { return category == EventCategory::Application; }

    };

    class TickEvent : public ApplicationEvent {

    private:
        double dt;

    public:

        explicit TickEvent(double dt) : dt(dt) {};

        EventType GetEventType() const override { return EventType::AppTick; }

        const char *GetName() const override { return "TickEvent"; }

        double GetDeltaTime() const { return dt; }

    };

    class RenderEvent : public ApplicationEvent {

    public:

        EventType GetEventType() const override { return EventType::AppRender; }

        const char *GetName() const override { return "RenderEvent"; }

    };



}


#endif //GESTALT_APPLICATIONEVENT_H
