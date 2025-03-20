#include "window/render_window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace pb {

RenderWindow::RenderWindow(int width, int height, const char *title) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  window_ = glfwCreateWindow(width, height, title, NULL, NULL);
  if (window_ == NULL) {
    glfwTerminate();
  }
  glfwMakeContextCurrent(window_);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
  }
  glfwSetWindowUserPointer(window_, this);
  glfwSetFramebufferSizeCallback(window_, framebufferSizeCallback);
  glfwSetKeyCallback(window_, inputCallback);
}

RenderWindow::~RenderWindow() { glfwDestroyWindow(window_); }

bool RenderWindow::isOpen() const { return glfwWindowShouldClose(window_); }

void RenderWindow::close() {
  glfwSetWindowShouldClose(window_, true);
}

void RenderWindow::clear(Color color) {
  glClearColor(color.r, color.g, color.b, color.a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void RenderWindow::clear(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void RenderWindow::display() {
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void RenderWindow::resize(int width, int height) {
  glViewport(0, 0, width, height);
  glfwSetWindowSize(window_, width, height);
}

GLFWwindow *RenderWindow::getGLFWwindow() const { return window_; }

void RenderWindow::framebufferSizeCallback(GLFWwindow *window, int width,
                                           int height) {
  RenderWindow *rw =
      static_cast<RenderWindow *>(glfwGetWindowUserPointer(window));
  rw->resize(width, height);
}

void RenderWindow::inputCallback(GLFWwindow *window, int key, int scancode,
                                 int action, int mods) {
  RenderWindow *rw =
      static_cast<RenderWindow *>(glfwGetWindowUserPointer(window));
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    rw->close();
  }
}

}  // namespace pb
