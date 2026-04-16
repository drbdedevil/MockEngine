#pragma once

#include <string>
#include "Log/Log.h"
#include "Event/InputEvent.h"  // !!

DEFINE_LOG_CATEGORY_STATIC(LogEvent);

namespace Mock
{
template <typename... Args>
class Event
{
public:
    void invoke(Args... args)
    {
        auto printEvent = [](const InputEvent& event)
        {
            std::string eventTypeStr;
            switch (event.type)
            {
                default: eventTypeStr = "Unknown"; break;
                case EventType::WindowClose: eventTypeStr = "WindowClose"; break;
                case EventType::WindowResize: eventTypeStr = "WindowResize"; break;
                case EventType::MouseMove: eventTypeStr = "MouseMove"; break;
                case EventType::MouseButton: eventTypeStr = "MouseButton"; break;
                case EventType::MouseScroll: eventTypeStr = "MouseScroll"; break;
                case EventType::KeyPress: eventTypeStr = "KeyPress"; break;
            }

            M_LOG(LogEvent, Display, "Dispatch event {}!", eventTypeStr);
        };

        (printEvent(args), ...);
    }
};
}  // namespace Mock