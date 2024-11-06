#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP
#include "Engine.hpp"

class DrawableObject {
  virtual void draw(Engine *engine) = 0;
};
#endif
