#include "LineSegment.hpp"

LineSegment::LineSegment(Point2D *start, Point2D *end) : _start(start), _end(end) {}
void LineSegment::draw(PrimitiveRenderer *renderer) {
  renderer->drawLine(_start->getX(), _start->getY(), _end->getX(), _end->getY());
}
