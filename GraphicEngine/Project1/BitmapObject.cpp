#include "BitmapObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void BitmapObject::rotate(float deg, Vector2D origin) {
  sprite.setOrigin(origin.x, origin.y);
  sprite.setRotation(deg);
}

void BitmapObject::translate(Vector2D vec) {
  sprite.move(vec.x, vec.y);
}

void BitmapObject::scale(float sx, float sy, Vector2D origin) {
  sprite.setOrigin(origin.x, origin.y);
  sprite.setScale(sx, sy);
}

void BitmapObject::draw(sf::RenderTarget *target) { 
  target->draw(sprite);
}

