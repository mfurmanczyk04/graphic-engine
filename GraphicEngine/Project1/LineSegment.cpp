#include "LineSegment.hpp"
#include "Vector2D.hpp"
#include <cmath>

LineSegment::LineSegment(Vector2D start, Vector2D end, sf::Color color) : _start(start), _end(end), _color(color) {}
  
void LineSegment::draw(PrimitiveRenderer *renderer) {
  renderer->drawLine(_start.x, _start.y, _end.x, _end.y, _color);
}

Vector2D LineSegment::getCenterPoint() {
  return Vector2D((_start.x + _end.x) / 2.0f, (_start.y + _end.y) / 2.0f);
}

void LineSegment::scale(float sx, float sy, Vector2D origin) {
  _start.x -= origin.x;
  _start.y -= origin.y;
  _end.x -= origin.x;
  _end.y -= origin.y;
  _start.x*=sx;
  _start.y*=sy;
  _end.x*=sx;
  _end.y*=sy;
  _start.x += origin.x;
  _start.y += origin.y;
  _end.x += origin.x;
  _end.y += origin.y;
}

void LineSegment::rotate(float deg, Vector2D origin) {
  float rad = deg * (M_PI / 180.0f);
  
  float cosAngle = std::cos(rad);
  float sinAngle = std::sin(rad);

  float startX = _start.x - origin.x;
  float startY = _start.y - origin.y;
  _start.x = origin.x + startX * cosAngle - startY * sinAngle;
  _start.y = origin.y + startX * sinAngle + startY * cosAngle;

  float endX = _end.x - origin.x;
  float endY = _end.y - origin.y;
  _end.x = origin.x + endX * cosAngle - endY * sinAngle;
  _end.y = origin.y + endX * sinAngle + endY * cosAngle;
}


void LineSegment::translate(Vector2D vec) {
  _start.x += vec.x;
  _start.y += vec.y;
  _end.x += vec.x;
  _end.y += vec.y;
}
