// PrimitiveRenderer.hpp
#ifndef PRIMITIVERENDERER_HPP
#define PRIMITIVERENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Color.hpp"
#include "Vector2D.hpp"

class PrimitiveRenderer {
public:
  PrimitiveRenderer(sf::RenderTexture *renderTexture) : _rt(renderTexture) {};
  void drawCircleBuiltin(float x, float y, float radius);
  void drawCircle(float x, float y, float radius);
  void drawEllipsis(float x, float y, float rx, float ry);
  void drawLineBuiltin(float x0, float y0, float x1, float y1);
  void drawLine(float x0, float y0ver, float x1, float y1);
  void drawPolyLine(std::vector<Vector2D> verts);
  void clearScreen();
  void setPixel(float x, float y);
  void setColor(Color color);
  void boundryFill(unsigned int x, unsigned int y, Color fillColor, Color backgroundColor, bool moore = false);
private:
  sf::RenderTexture *_rt;
  sf::Color _color = sf::Color::White;
};
#endif
