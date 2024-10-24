// Line2D.hpp
#ifndef LINE2D_HPP
#define LINE2D_HPP

#include "IDrawable.hpp"
#include "Point2D.hpp"
class Line2D : public IDrawable {
public:
  Line2D(Point2D *start, Point2D *end);
  void draw(PrimitiveRenderer *renderer) override;

private:
  Point2D *_start;
  Point2D *_end;
};
#endif
