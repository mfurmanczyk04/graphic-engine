#include "PrimitiveRenderer.hpp"
#include <SFML/Graphics/CircleShape.hpp>

sf::Color sfColorFromColor(Color color) {
  return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius, Color color) {
  sf::CircleShape circleShape;
  circleShape.setPosition(x, y);
  circleShape.setFillColor(sfColorFromColor(color));
  circleShape.setRadius(radius);
  _window->draw(circleShape);
}


void PrimitiveRenderer::drawLine(float x1, float y1, float x2, float y2, Color color) {
  sf::Vertex lineVerts[2] = {
    sf::Vertex(sf::Vector2(x1, y1)),
    sf::Vertex(sf::Vector2(x2, y2)),
  };

  _window->draw(lineVerts, 2, sf::Lines);
}

void PrimitiveRenderer::clearScreen(Color color) {
  _window->clear(sfColorFromColor(color));
}


