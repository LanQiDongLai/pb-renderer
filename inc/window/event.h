#pragma once

#include <variant>

namespace pb {

class Event {
 public:
  enum class EventType {
    WindowClose,
    WindowResize,
    KeyPressed,
    KeyReleased,
    KeyTyped,
    MouseLeftButtonPressed,
    MouseLeftButtonReleased,
    MouseRightButtonPressed,
    MouseRightButtonReleased,
    MouseMiddleButtonPressed,
    MouseMiddleButtonReleased,
    MouseMoved,
    MouseScrolled
  };
  struct WindowResize {
    int width;
    int height;
  };
  struct KeyPressed {
    int key;
    int scancode;
    int mods;
  };
  struct KeyReleased {
    int key;
    int scancode;
    int mods;
  };
  struct KeyTyped {
    int key;
  };
  struct MouseLeftButtonPressed {
    double xpos;
    double ypos;
  };
  struct MouseLeftButtonReleased {
    double xpos;
    double ypos;
  };
  struct MouseRightButtonPressed {
    double xpos;
    double ypos;
  };
  struct MouseRightButtonReleased {
    double xpos;
    double ypos;
  };
  struct MouseMiddleButtonPressed {
    double xpos;
    double ypos;
  };
  struct MouseMiddleButtonReleased {
    double xpos;
    double ypos;
  };
  struct MouseMoved {
    double xpos;
    double ypos;
  };
  struct MouseScrolled {
    double xpos;
    double ypos;
    double scroll_value;
  };
  std::variant<MouseLeftButtonPressed, MouseLeftButtonReleased,
               MouseRightButtonPressed, MouseRightButtonReleased,
               MouseMiddleButtonPressed, MouseMiddleButtonReleased, MouseMoved,
               MouseScrolled, KeyPressed, KeyReleased, KeyTyped, WindowResize>
      data;
  EventType type;
  Event(EventType type) : type(type) {}
  virtual ~Event() = default;
};

}  // namespace pb