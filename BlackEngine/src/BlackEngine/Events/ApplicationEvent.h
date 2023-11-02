#pragma once

#include "./Event.h"
#include <sstream>

namespace BlackEngine {
class WindowResizeEvent : public Event {

public:
  WindowResizeEvent(int _width, int _height) : width(_width), height(_height) {}

  inline int getWidth() const { return width; }
  inline int getHeight() const { return height; }

  std::string toString() const override {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << width << ", " << height;
    return ss.str();
  }

  static EventType getStaticType() { return EventType::WindowResize; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual int getCategoryFlags() const override {
    return EventCategory::EventCategoryApplication;
  }
  virtual const char *getName() const override { return "WindowResize"; }

private:
  int width;
  int height;
};

class WindowCloseEvent : public Event {

public:
    WindowCloseEvent() {}
    
    static EventType getStaticEvent() { return EventType::WindowClose; }
    virtual EventType getEventType() const override { return getStaticEvent(); }
    virtual int getCategoryFlags() const override { return EventCategory::EventCategoryApplication; } 
    virtual const char *getName() const override { return "WindowClose"; }
};

} // namespace BlackEngine
