#pragma once

#include "item/tessellable.h"
#include "utils/point2d.h"

namespace pb {

class Rectangle : public Tessellable {
 public:
  Rectangle(const Point2D &left_top, const Point2D &right_bottom);
  virtual ~Rectangle() = 0;
  Point2D GetLeftTop() const;
  Point2D GetRightBottom() const;
  void SetLeftTop(const Point2D &left_top);
  void SetRightBottom(const Point2D &right_bottom);
  std::vector<float> getVertices() const override;

 private:
  Point2D left_top;
  Point2D right_bottom;
};

}  // namespace pb