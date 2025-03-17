#pragma once
#include <vector>
#include "utils/point2d.h"

namespace pb {

class Tessellable {
 public:
  virtual ~Tessellable() = 0;
  virtual std::vector<float> getVertices() const = 0;
};

}  // namespace pb