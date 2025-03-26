#include <iostream>

#include "window/render_window.h"

int main() {
  pb::RenderWindow window(800, 600, "Hello, World!");

  while (!window.isOpen()) {
    std::optional<pb::Event> event = window.pollEvent();
    if(event.has_value()) {
      if(event->type == pb::Event::EventType::WindowClose) {
        window.close();
      }
      if(event->type == pb::Event::EventType::WindowResize) {
        auto resize = std::get<pb::Event::WindowResize>(event->data);
        window.resizeView(resize.width, resize.height);
      }
      if(event->type == pb::Event::EventType::MouseLeftButtonPressed) {
        auto mouse = std::get<pb::Event::MouseLeftButtonPressed>(event->data);
        std::cout << "Mouse left button pressed at: " << mouse.xpos << ", " << mouse.ypos << std::endl;
      }
    }
    window.clear(1.0f, 0.5f, 0.1f, 1.0f);
    window.display();
  }
  return 0;
}