#include "item/rectangle.h"

namespace pb {

Rectangle::Rectangle(const Point2D &left_top, const Point2D &right_bottom)
    : left_top(left_top), right_bottom(right_bottom) {}

Point2D Rectangle::GetLeftTop() const { return left_top; }

Point2D Rectangle::GetRightBottom() const { return right_bottom; }

void Rectangle::SetLeftTop(const Point2D &left_top) {
  this->left_top = left_top;
}

void Rectangle::SetRightBottom(const Point2D &right_bottom) {
  this->right_bottom = right_bottom;
}

std::vector<float> Rectangle::getVertices() const {
  return {
      left_top.x,     left_top.y,     0., left_top.x,     right_bottom.y, 0.,
      right_bottom.x, right_bottom.y, 0., right_bottom.x, left_top.y,     0.,
      left_top.x,     left_top.y,     0.};
}

}  // namespace pb


