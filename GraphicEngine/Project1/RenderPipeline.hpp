#ifndef RENDERPIPELINE_HPP
#define RENDERPIPELINE_HPP

#include "PrimitiveRenderer.hpp"
class RenderPipeline {
public:
  virtual PrimitiveRenderer *getPrimitiveRenderer() = 0;
};
#endif
