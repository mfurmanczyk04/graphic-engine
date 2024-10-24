#include "PrimitiveRenderer.hpp"

sf::Color sfColorFromColor(Color color) {
  return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius, Color color) {
  circleShape.setPosition(x, y);
  circleShape.setFillColor(sfColorFromColor(color));
  circleShape.setRadius(radius);
  _window->draw(circleShape);
}
