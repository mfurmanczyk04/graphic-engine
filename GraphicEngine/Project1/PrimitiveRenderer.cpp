#include "PrimitiveRenderer.hpp"
#include <SFML/Graphics/CircleShape.hpp>

sf::Color sfColorFromColor(Color color) {
  return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius) {
  sf::CircleShape circleShape;
  circleShape.setPosition(x, y);
  circleShape.setFillColor(_color);
  circleShape.setRadius(radius);
  _window->draw(circleShape);
}


void PrimitiveRenderer::setPixel(float x, float y) {
  auto vert = sf::Vertex(sf::Vector2(x,y));
  _window->draw(&vert, 1, sf::Points);
}

void PrimitiveRenderer::setColor(Color color) {
  _color = sfColorFromColor(color);
}

void PrimitiveRenderer::drawLine(float x1, float y1, float x2, float y2) {
  sf::Vertex lineVerts[2] = {
    sf::Vertex(sf::Vector2(x1, y1)),
    sf::Vertex(sf::Vector2(x2, y2)),
  };
  _window->draw(lineVerts, 2, sf::Lines);
}

void PrimitiveRenderer::clearScreen() {
  _window->clear(_color);
}


