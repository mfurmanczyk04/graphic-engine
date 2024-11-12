#ifndef BITMAPOBJECT_HPP
#define BITMAPOBJECT_HPP

#include "DrawableObject.hpp"
#include "TransformableObject.hpp"
#include "Vector2D.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

class BitmapObject : public DrawableObject, public TransformableObject {
public:
  BitmapObject(Vector2D position, sf::Texture bitmap)
      :  texture(bitmap) {

      texture.setPosition(position.x, position.y);
  }

  void draw(Renderer *rp) override { draw(rp->getRenderTarget()); };
  void draw(sf::RenderTarget *target);


  void translate(Vector2D vec) override;
  void rotate(float deg, Vector2D origin) override;
  void scale(float sx, float sy, Vector2D origin) override;

protected:
  sf::Sprite texture;
};

#endif
