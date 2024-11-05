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
  std::vector<Vector2D> drawLine(float x0, float y0, float x1, float y1);
  void drawPolyLine(const std::vector<Vector2D> &verts);
  void drawPoly(std::vector<Vector2D> &verts, bool full = false);
  void clearScreen();
  void setPixel(float x, float y);
  void setPixels(const std::vector<Vector2D> &verts);
  void setColor(Color color);
  std::vector<Vector2D> boundryFill(const std::vector<Vector2D> &circVerts, Vector2D origin);

private:
  sf::RenderTexture *_rt;
  sf::Color _color = sf::Color::White;
};
#endif
