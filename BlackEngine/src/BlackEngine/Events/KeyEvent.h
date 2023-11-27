#pragma once

#include "Event.h"

namespace BlackEngine {

class BLACK_ENGINE_API KeyEvent : public Event {
public:
  inline int getKeyCode() const { return keyCode; }

  virtual int getCategoryFlags() const override {
    return EventCategory::EventCategoryKeyboard |
           EventCategory::EventCategoryInput;
  }

protected:
  KeyEvent(int keycode) : keyCode(keycode){};
  int keyCode;
};

class BLACK_ENGINE_API KeyPressedEvent : public KeyEvent {
public:
  KeyPressedEvent(int _keycode, int _repeatCount)
      : KeyEvent(_keycode), repeatCount(_repeatCount){};

  inline int getRepeatCount() const { return repeatCount; }

  std::string toString() const override {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
    return ss.str();
  }

  static EventType getStaticType() { return EventType::KeyPressed; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual const char *getName() const override { return "KeyPressed"; }

private:
  int repeatCount;
};


class BLACK_ENGINE_API KeyReleasedEvent : public KeyEvent {
public:
  KeyReleasedEvent(int _keycode)
      : KeyEvent(_keycode){};

  std::string toString() const override {
    std::stringstream ss;
    ss << "KeyReleasedEvent: " << keyCode;
    return ss.str();
  }

  static EventType getStaticType() { return EventType::KeyReleased; }
  virtual EventType getEventType() const override { return getStaticType(); }
  virtual const char *getName() const override { return "KeyReleased"; }
};



} // namespace BlackEngine
