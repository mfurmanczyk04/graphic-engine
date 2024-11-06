#ifndef POINT2D_HPP
#define POINT2D_HPP

#include "IDrawable.hpp"
#include "PrimitiveRenderer.hpp"
#include "Vector2D.hpp"

class Point2D : public IDrawable {
public:
  Vector2D getPosition();
  void setPosition(Vector2D position);
  void draw(PrimitiveRenderer *renderer) override;
  Point2D(Vector2D position, sf::Color color);
private:
  Vector2D _position;
  sf::Color _color;
};

#endif
