#ifndef SHAPEOBJECT_HPP
#define SHAPEOBJECT_HPP
#include "DrawableObject.hpp"
#include "PrimitiveRenderer.hpp"

class ShapeObject : public DrawableObject {
public:  
  void virtual draw(PrimitiveRenderer *pr) = 0;
  void draw(Renderer *rp) override { return draw(rp->getPrimitiveRenderer()); }
};
#endif
