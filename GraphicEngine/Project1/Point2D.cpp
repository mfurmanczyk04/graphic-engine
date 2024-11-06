#include "Point2D.hpp"

Point2D::Point2D(Vector2D position, sf::Color color): _position(position), _color(color) {}

Vector2D Point2D::getPosition() { return _position; }
void Point2D::setPosition(Vector2D position) { _position = position; }

void Point2D::draw(PrimitiveRenderer *renderer) {
  renderer->setPixel(_position.x, _position.y, _color);
}

