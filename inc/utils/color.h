#pragma once

namespace pb {
class Color {
 public:
  float r;
  float g;
  float b;
  float a;

  Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
};
}