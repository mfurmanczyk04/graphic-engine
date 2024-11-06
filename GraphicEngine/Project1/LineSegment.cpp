#include "LineSegment.hpp"

LineSegment::LineSegment(Vector2D start, Vector2D end, sf::Color color) : _start(start), _end(end), _color(color) {}
  
void LineSegment::draw(PrimitiveRenderer *renderer) {
  renderer->drawLine(_start.x, _start.y, _end.x, _end.y, _color);
}
