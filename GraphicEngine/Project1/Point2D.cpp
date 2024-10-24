#include "Point2D.hpp"

void Point2D::draw(PrimitiveRenderer *renderer) {
  renderer->drawCircle(_x, _y, 1, Color::Magenta);
}
