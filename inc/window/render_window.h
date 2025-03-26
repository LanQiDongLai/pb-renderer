#pragma once
#include "utils/color.h"
#include "window/event.h"
#include <queue>
#include <optional>

struct GLFWwindow;
namespace pb {
class RenderWindow {
 public:
  RenderWindow(int width, int height, const char* title);
  ~RenderWindow();
  bool isOpen() const;
  void close();
  void clear(Color color);
  void clear(float r, float g, float b, float a);
  void display();
  void resize(int width, int height);
  std::optional<Event> pollEvent();

  GLFWwindow* getGLFWwindow() const;

  void resizeView(int width, int height);
 private:
  static void windowSizeCallback(GLFWwindow* window, int width,
                                      int height);
  static void inputCallback(GLFWwindow* window, int key, int scancode,
                            int action, int mods);
  
  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
  static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
  GLFWwindow* window_;
  std::queue<Event> event_queue_;
};

}  // namespace pb
