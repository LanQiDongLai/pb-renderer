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
  glfwSetWindowSizeCallback(window_, windowSizeCallback);
  glfwSetKeyCallback(window_, inputCallback);
  glfwSetMouseButtonCallback(window_, mouseButtonCallback);
  glfwSetCursorPosCallback(window_, cursorPositionCallback);
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
  glfwSetWindowSize(window_, width, height);
}

std::optional<Event> RenderWindow::pollEvent() {
  if(event_queue_.empty()) {
    return std::nullopt;
  }
  auto event = event_queue_.front();
  event_queue_.pop();
  return event;
}

void RenderWindow::resizeView(int width, int height) {
  glViewport(0, 0, width, height);
}

GLFWwindow *RenderWindow::getGLFWwindow() const { return window_; }

void RenderWindow::windowSizeCallback(GLFWwindow *window, int width,
                                           int height) {
  RenderWindow *rw =
      static_cast<RenderWindow *>(glfwGetWindowUserPointer(window));
  Event event(Event::EventType::WindowResize);
  event.data = Event::WindowResize{width, height};
  rw->event_queue_.push(event);
}

void RenderWindow::inputCallback(GLFWwindow *window, int key, int scancode,
                                 int action, int mods) {
  RenderWindow *rw =
      static_cast<RenderWindow *>(glfwGetWindowUserPointer(window));
  Event event(Event::EventType::KeyPressed);
  event.data = Event::KeyPressed{key, scancode, mods};
  rw->event_queue_.push(event);
}

void RenderWindow::mouseButtonCallback(GLFWwindow *window, int button,
                                       int action, int mods) {
  RenderWindow *rw =
      static_cast<RenderWindow *>(glfwGetWindowUserPointer(window));
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    Event event(Event::EventType::MouseLeftButtonPressed);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    event.data = Event::MouseLeftButtonPressed{xpos, ypos};
    rw->event_queue_.push(event);
    return;
  }

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    Event event(Event::EventType::MouseLeftButtonReleased);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    event.data = Event::MouseLeftButtonReleased{xpos, ypos};
    rw->event_queue_.push(event);
    return;
  }

  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
    Event event(Event::EventType::MouseRightButtonPressed);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    event.data = Event::MouseRightButtonPressed{xpos, ypos};
    rw->event_queue_.push(event);
    return;
  }

  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
    Event event(Event::EventType::MouseRightButtonReleased);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    event.data = Event::MouseRightButtonReleased{xpos, ypos};
    rw->event_queue_.push(event);
    return;
  }

  if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
    Event event(Event::EventType::MouseMiddleButtonPressed);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    event.data = Event::MouseMiddleButtonPressed{xpos, ypos};
    rw->event_queue_.push(event);
    return;
  }

  if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE) {
    Event event(Event::EventType::MouseMiddleButtonReleased);
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    event.data = Event::MouseMiddleButtonReleased{xpos, ypos};
    rw->event_queue_.push(event);
    return;
  }
}

void RenderWindow::cursorPositionCallback(GLFWwindow *window, double xpos,
                                          double ypos) {
  RenderWindow *rw =
      static_cast<RenderWindow *>(glfwGetWindowUserPointer(window));
  Event event(Event::EventType::MouseMoved);
  event.data = Event::MouseMoved{xpos, ypos};
  rw->event_queue_.push(event);
}

}  // namespace pb
