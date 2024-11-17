// PrimitiveRenderer.hpp
#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Vector2D.hpp"

class PrimitiveRenderer {
public:
  void drawCircle(float x, float y, float radius, sf::Color color, sf::Color fill = sf::Color::Transparent);
  void drawEllipsis(float x, float y, float rx, float ry, sf::Color color, sf::Color fill = sf::Color::Transparent);
  void drawLine(float x0, float y0, float x1, float y1, sf::Color color);
  void drawPolyLine(const std::vector<Vector2D> &verts, sf::Color color);
  void drawPoly(std::vector<Vector2D> verts, sf::Color color, sf::Color fill = sf::Color::Transparent);
  void setPixel(int x, int y, sf::Color color);
  void setPixels(const std::vector<Vector2D> &verts, sf::Color color);
  void boundaryFill(int x, int y, sf::Color fillColor, sf::Color boundaryColor);
  void drawRect(float x, float y, float w, float h, sf::Color color, sf::Color fill = sf::Color::Transparent);
  void setImage(sf::Image *image);
private:
  sf::Image *_output = nullptr;
  bool isPixelInBounds(int x, int y);
};
#endif
