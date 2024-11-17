
#include "CircleShape.hpp"
#include "Vector2D.hpp"


void CircleShape::translate(Vector2D vec) {
  position.x += vec.x;
  position.y += vec.y;
}
void CircleShape::setPosition(Vector2D pos) {
  position.x = pos.x;
  position.y = pos.y;
}

void CircleShape::rotate(float deg, Vector2D origin) {
  return; 
}

void CircleShape::scale(float sx, float sy, Vector2D origin) {
  radius *= std::max(sx,sy);
}

void CircleShape::draw(PrimitiveRenderer *pr) {
  pr->drawCircle(position.x, position.y, radius, color, fillColor);
}
CircleShape::CircleShape(Vector2D position, float radius, sf::Color color, sf::Color fillColor) 
: position(position), radius(radius), color(color), fillColor(fillColor)
{}

