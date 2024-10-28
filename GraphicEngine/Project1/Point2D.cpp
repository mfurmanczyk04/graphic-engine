#include "Point2D.hpp"

Point2D::Point2D(Vector2D position): _position(position) {}

Vector2D Point2D::getPosition() { return _position; }
void Point2D::setPosition(Vector2D position) { _position = position; }

void Point2D::draw(PrimitiveRenderer *renderer) {
  renderer->setPixel(_position.getX(), _position.getY());
}

