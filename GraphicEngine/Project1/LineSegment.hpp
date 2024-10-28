// LineSegment.hpp
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "IDrawable.hpp"
#include "Point2D.hpp"
class LineSegment : public IDrawable {
public:
  LineSegment(Point2D *start, Point2D *end);
  void draw(PrimitiveRenderer *renderer) override;

private:
  Point2D *_start;
  Point2D *_end;
};
#endif
