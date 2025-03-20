#pragma once
#include "utils/color.h"

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

  GLFWwindow* getGLFWwindow() const;

 private:
  static void framebufferSizeCallback(GLFWwindow* window, int width,
                                      int height);
  static void inputCallback(GLFWwindow* window, int key, int scancode,
                            int action, int mods);
  GLFWwindow* window_;
};
}  // namespace pb
