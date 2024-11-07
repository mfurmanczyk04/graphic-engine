
#include "Circle.hpp"
#include "Vector2D.hpp"


void Circle::translate(Vector2D vec) {
  position.x += vec.x;
  position.y += vec.y;
}
void Circle::setPosition(Vector2D pos) {
  position.x = pos.x;
  position.y = pos.y;
}

void Circle::rotate(float deg, Vector2D origin) {
  return; 
}

void Circle::scale(float sx, float sy, Vector2D origin) {
  radius *= std::max(sx,sy);
}

void Circle::draw(PrimitiveRenderer *pr) {
  pr->drawCircle(position.x, position.y, radius, color, fillColor);
}
Circle::Circle(Vector2D position, float radius, sf::Color color, sf::Color fillColor) 
: position(position), radius(radius), color(color), fillColor(fillColor)
{}

