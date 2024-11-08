#ifndef BITMAPOBJECT_HPP
#define BITMAPOBJECT_HPP

#include "DrawableObject.hpp"
#include "Vector2D.hpp"

class BitmapObject : public DrawableObject {
public:
  BitmapObject(Vector2D origin, sf::Texture bitmap)
      : origin(origin), sprite(bitmap) {}
  void draw(Renderer *rp);

private:
  Vector2D origin;
  sf::Sprite sprite;
};

#endif
