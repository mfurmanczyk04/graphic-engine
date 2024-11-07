// ScreenPoint2D.hpp
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

struct Vector2D {
public:
  Vector2D(float x, float y) : x(x), y(y) {}
  Vector2D(const Vector2D &v) : x(v.x), y(v.y) {}
  float x;
  float y;
};
#endif
