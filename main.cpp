#include <iostream>

#include "window/render_window.h"

int main() {
  pb::RenderWindow window(800, 600, "Hello, World!");

  while (!window.isOpen()) {
    window.clear(0.f, 0.f, 0.f, 1.0f);
    window.display();
  }

  return 0;
}