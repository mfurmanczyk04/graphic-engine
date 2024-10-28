#include "LineSegment.hpp"

LineSegment::LineSegment(Vector2D *start, Vector2D *end) : _start(start), _end(end) {}
void LineSegment::draw(PrimitiveRenderer *renderer) {
  renderer->drawLineBuiltin(_start->getX(), _start->getY(), _end->getX(), _end->getY());
}
