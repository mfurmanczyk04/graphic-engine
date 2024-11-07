#ifndef TRANSFORMABLEOBJECT_HPP
#define TRANSFORMABLEOBJECT_HPP

#include "GameObject.hpp"
#include "Vector2D.hpp"

class TransformableObject : public GameObject {
public:
  virtual void translate(Vector2D vec)  = 0;
  virtual void rotate(float deg, Vector2D origin) = 0;
  virtual void scale(float sx, float sy, Vector2D origin) = 0;
};
#endif
