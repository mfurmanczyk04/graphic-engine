#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP

#include "Engine.hpp"
#include "GameObject.hpp"

class DrawableObject : public GameObject {
  virtual void draw(Engine *engine) = 0;
};
#endif
