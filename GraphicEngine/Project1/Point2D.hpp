// Point2D.hpp
#ifndef POINT2D_HPP
#define POINT2D_HPP
#include "PrimitiveRenderer.hpp"
class Point2D {
public:
  Point2D(float x, float y) : _x(x), _y(y) {}

  float getX() { return _x; }
  void setX(float x) { _x = x;}

  float getY() { return _y; }
  void setY(float y) { _y = y;}

  void draw(PrimitiveRenderer *renderer);
private:
  float _x;
  float _y;
};
#endif
