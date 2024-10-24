// PrimitiveRenderer.hpp
#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Color.hpp"

class PrimitiveRenderer {
public:
  PrimitiveRenderer(sf::RenderWindow *window) : _window(window) {};
  void drawCircle(float x, float y, float radius, Color color);
  void drawLine(float x1, float y1, float x2, float y2, Color color);
  void clearScreen(Color color);

private:
  sf::RenderWindow *_window;
};
#endif
