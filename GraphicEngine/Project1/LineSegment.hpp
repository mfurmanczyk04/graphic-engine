// LineSegment.hpp
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "Vector2D.hpp"
#include "ShapeObject.hpp"
#include "TransformableObject.hpp"


class LineSegment : public ShapeObject, public TransformableObject {
public:
  LineSegment(Vector2D start, Vector2D end, sf::Color color);
  void draw(PrimitiveRenderer *renderer) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void rotate(float deg, Vector2D origin) override;
  void translate(Vector2D vec)  override;
  Vector2D getCenterPoint();
private:
  Vector2D _start;
  Vector2D _end;
  sf::Color _color;
  Vector2D getOriginPoint();
};
#endif
