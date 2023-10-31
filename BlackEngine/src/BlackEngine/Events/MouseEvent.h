#pragma once
#include "Event.h"
#include <sstream>

namespace BlackEngine {

class BLACK_ENGINE_API MouseMovedEvent : public Event {
public:
  MouseMovedEvent(float x, float y) : mouseX(x), mouseY(y) {}

  inline float getX() const { return mouseX; }
  inline float getY() const { return mouseY; }

  std::string toString() const override {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
    return ss.str();
  }

  static EventType getStaticType() { return EventType::MouseMoved; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual int getCategoryFlags() const override {
    return EventCategory::EventCategoryMouse |
           EventCategory::EventCategoryInput;
  };
  virtual const char *getName() const override { return "MouseMoved"; }

private:
  float mouseX;
  float mouseY;
};

} // namespace BlackEngine
