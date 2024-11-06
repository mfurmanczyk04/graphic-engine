#ifndef TRANSFORMABLEOBJECT_HPP
#define TRANSFORMABLEOBJECT_HPP
#include "Vector2D.hpp"
class TransformableObject {
public:
  virtual void translate(float x, float y) = 0;
  void translate(Vector2D vec)  { translate(vec.x, vec.y); }

  virtual Vector2D getCenterPoint() = 0;

  virtual void rotate(float deg, Vector2D origin) = 0;
  void rotate(float deg)  { rotate(deg, getCenterPoint()); }

  virtual void scale(float sx, float sy, Vector2D origin) = 0;
  void scale(float sx, float sy)  { scale(sx, sy, getCenterPoint()); }
  void scale(float s, Vector2D origin)  { scale(s, s, origin); }
  void scale(float s)  { scale(s, s, getCenterPoint()); }
};
#endif
