// PrimitiveRenderer.hpp
#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "Color.hpp"

class PrimitiveRenderer {
public:
  PrimitiveRenderer(sf::RenderWindow *window): _window(window) {};
  void drawCircle(float x, float y, float radius, Color color);
private:
  sf::RenderWindow *_window;
  sf::CircleShape circleShape;
};
#endif
