#ifndef RENDERPIPELINE_HPP
#define RENDERPIPELINE_HPP

#include "PrimitiveRenderer.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
class Renderer {
public:
  virtual PrimitiveRenderer *getPrimitiveRenderer() = 0;
  virtual sf::RenderTarget *getRenderTarget() = 0;
  virtual void beginPrimitiveBatch() = 0;
  virtual void endPrimitiveBatch() = 0;
};
#endif
