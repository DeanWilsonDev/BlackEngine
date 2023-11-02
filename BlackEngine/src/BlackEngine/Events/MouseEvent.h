#pragma once
#include "Event.h"
#include <sstream>
#include "../Core/MouseCode.h"

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

class BLACK_ENGINE_API MouseScrolledEvent : public Event {
public:
  MouseScrolledEvent(float xOffset, float yOffset)
      : xOffset(xOffset), yOffset(yOffset) {}

  inline float getXOffset() const { return xOffset; }
  inline float getYOffset() const { return yOffset; }

  std::string toString() const override {
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
    return ss.str();
  }

  static EventType getStaticType() { return EventType::MouseScrolled; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual int getCategoryFlags() const override {
    return EventCategory::EventCategoryMouse |
           EventCategory::EventCategoryInput;
  }

  virtual const char *getName() const override { return "MouseScrolled"; }

private:
  float xOffset;
  float yOffset;
};

class BLACK_ENGINE_API MouseButtonEvent : public Event {

  inline MouseCode getButton() const { return button; }

  virtual int getCategoryFlags() const override {
    return EventCategory::EventCategoryMouse |
            EventCategoryMouseButton |
           EventCategory::EventCategoryInput;
  }

protected:
  MouseButtonEvent(MouseCode button) : button(button) {}
  MouseCode button;
};

class BLACK_ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent {
public:
  MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}


  std::string toString() const override {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << button;
    return ss.str();
  }

  static EventType getStaticType() { return EventType::MouseButtonPressed; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual const char *getName() const override { return "MouseButtonPressed"; }

private:
  int button;
};

class BLACK_ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent {
public:
  MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

  std::string toString() const override {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << button;
    return ss.str();
  }

  static EventType getStaticType() { return EventType::MouseButtonReleased; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual const char *getName() const override { return "MouseButtonReleased"; }
};

} // namespace BlackEngine
