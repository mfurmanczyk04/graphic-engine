// Vector2D.hpp
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D {
public:
  Vector2D(float x, float y) : _x(x), _y(y) {}

  float getX() { return _x; }
  void setX(float x) { _x = x;}

  float getY() { return _y; }
  void setY(float y) { _y = y;}
private:
  float _x;
  float _y;
};
#endif
