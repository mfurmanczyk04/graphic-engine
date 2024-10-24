// Engine.hpp
#ifndef IDRAWABLE_HPP
#define IDRAWABLE_HPP
#include "PrimitiveRenderer.hpp"

class IDrawable {
public:
  virtual void draw(PrimitiveRenderer *renderer) = 0; 
};

#endif
