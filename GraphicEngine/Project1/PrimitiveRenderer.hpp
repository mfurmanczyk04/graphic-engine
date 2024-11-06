// PrimitiveRenderer.hpp
#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Vector2D.hpp"

class PrimitiveRenderer {
public:
  void drawCircle(float x, float y, float radius, sf::Color color);
  void drawEllipsis(int x, int y, int rx, int ry, sf::Color color);
  void drawLine(int x0, int y0, int x1, int y1, sf::Color color);
  void drawPolyLine(const std::vector<Vector2D> &verts, sf::Color color);
  void drawPoly(std::vector<Vector2D> &verts, sf::Color color, bool full = false);
  void clearScreen();
  void setPixel(int x, int y, sf::Color color);
  void setPixels(const std::vector<Vector2D> &verts, sf::Color color);
  void boundaryFill(int x, int y, sf::Color fillColor, sf::Color boundaryColor);
  void setImage(sf::Image *image);
private:
  sf::Image *_output = nullptr;
};
#endif
