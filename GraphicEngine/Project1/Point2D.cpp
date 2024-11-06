#include "Point2D.hpp"
#include "Vector2D.hpp"

Point2D::Point2D(Vector2D position, sf::Color color): _position(position), _color(color) {}

Vector2D Point2D::getPosition() { return _position; }
void Point2D::setPosition(Vector2D position) { _position = position; }

void Point2D::draw(PrimitiveRenderer *renderer) {
  renderer->setPixel(_position.x, _position.y, _color);
}

Vector2D Point2D::getCenterPoint() { return _position; }
void Point2D::rotate(float deg, Vector2D origin) { return; }
void Point2D::scale(float sx, float sy, Vector2D origin)  { return; }
void Point2D::translate(float x, float y) {
  _position.x += x;
  _position.y += y;
}

