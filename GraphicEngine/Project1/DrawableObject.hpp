#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP

#include "GameObject.hpp"
#include "Renderer.hpp"

class DrawableObject : public virtual GameObject {
public:
  virtual void draw(Renderer *rp) = 0;
};
#endif
