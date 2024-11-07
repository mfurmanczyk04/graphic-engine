#ifndef POINT2D_HPP
#define POINT2D_HPP

#include "PrimitiveRenderer.hpp"
#include "ShapeObject.hpp"
#include "TransformableObject.hpp"
#include "Vector2D.hpp"

class Point2D : public ShapeObject, public TransformableObject {
public:
  Vector2D getPosition();
  void setPosition(Vector2D position);
  void draw(PrimitiveRenderer *renderer) override;
  void translate(Vector2D vec) override;
  void rotate(float deg, Vector2D origin) override;
  void scale(float sx, float sy, Vector2D origin) override;
  Point2D(Vector2D position, sf::Color color);
private:
  Vector2D _position;
  sf::Color _color;
};

#endif
