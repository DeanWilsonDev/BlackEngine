
#pragma once

#include "../Core.h"

namespace BlackEngine {

// NOTE: This Events system is currently blocking.
// This means that events are handled on the spot, syncronously.
// In the future, it might be good to move to a buffering events system which
// would allow for asynchronous events.

enum class EventType {
  None = 0,
  WindowClose,
  WindowResize,
  WindowFocus,
  WindowLostFocus,
  WindowMoved,
  AppTick,
  AppUpdate,
  AppRender,
  KeyPressed,
  KeyReleased,
  MouseButtonPressed,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled
};

enum EventCategory {
  None = 0,
  EventCategoryApplication = BIT(0),
  EventCategoryInput = BIT(1),
  EventCategoryKeyboard = BIT(2),
  EventCategoryMouse = BIT(3),
  EventCategoryMouseButton = BIT(4)
};

class BLACK_ENGINE_API Event {
  friend class EventDispatcher;

public:
  virtual EventType getEventType() const = 0;
  virtual const char *getName() const = 0;
  virtual int getCategoryFlags() const = 0;
  virtual std::string toString() const { return getName(); }

  inline bool IsInCategory(EventCategory category) {
    return getCategoryFlags() & category;
  }

protected:
  bool handled = false;
};

class EventDispatcher {
  template <typename T> using eventFn = std::function<bool(T &)>;

public:
  EventDispatcher(Event &_event) : event(_event) {}

  template <typename T> bool dispatch(eventFn<T> func) {
    if (event.getEventType() == T::getStaticType()) {
      event.handled = func(*(T *)&event);
      return true;
    }
    return false;
  }

private:
  Event &event;
};

} // namespace BlackEngine
