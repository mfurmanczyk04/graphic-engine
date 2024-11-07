#ifndef DRAWABLEOBJECT_HPP
#define DRAWABLEOBJECT_HPP

#include "GameObject.hpp"
#include "RenderPipeline.hpp"

class DrawableObject : public GameObject {
  virtual void draw(RenderPipeline *rp) = 0;
};
#endif
