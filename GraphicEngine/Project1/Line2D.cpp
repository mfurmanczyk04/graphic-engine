#include "Line2D.hpp"

Line2D::Line2D(Point2D *start, Point2D *end) : _start(start), _end(end) {}
void Line2D::draw(PrimitiveRenderer *renderer) {
  renderer->drawLine(_start->getX(), _start->getY(), _end->getX(), _end->getY(), Color::White);
}
