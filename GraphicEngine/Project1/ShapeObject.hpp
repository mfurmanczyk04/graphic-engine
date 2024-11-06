
#ifndef SHAPEOBJECT_HPP
#define SHAPEOBJECT_HPP
#include "DrawableObject.hpp"
#include "Engine.hpp"
#include "PrimitiveRenderer.hpp"

class ShapeObject : DrawableObject {
public:  
  void virtual draw(PrimitiveRenderer *pr) = 0;
  void draw(Engine *engine) override {
    return draw(engine->getPrimitiveRenderer());
  }
};
#endif
