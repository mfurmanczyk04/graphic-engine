// PrimitiveRenderer.hpp
#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Color.hpp"
#include "Point2D.hpp"

class PrimitiveRenderer {
public:
  PrimitiveRenderer(sf::RenderWindow *window) : _window(window) {};
  void drawCircle(float x, float y, float radius);
  void drawLine(float x1, float y1, float x2, float y2);
  void drawVerts(std::vector<Point2D> verts);
  void clearScreen();
  void setPixel(float x, float y);
  void setColor(Color color);
private:
  sf::RenderWindow *_window;
  sf::Color _color = sf::Color::White;
};
#endif
