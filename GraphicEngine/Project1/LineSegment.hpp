// LineSegment.hpp
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "IDrawable.hpp"
#include "Vector2D.hpp"
class LineSegment : public IDrawable {
public:
  LineSegment(Vector2D start, Vector2D end, sf::Color color);
  void draw(PrimitiveRenderer *renderer) override;

private:
  Vector2D _start;
  Vector2D _end;
  sf::Color _color;
};
#endif
