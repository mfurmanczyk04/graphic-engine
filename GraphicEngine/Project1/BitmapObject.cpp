#include "BitmapObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>


void BitmapObject::rotate(float deg, Vector2D origin) {
  texture.setOrigin(origin.x, origin.y);
  texture.setRotation(deg);
}

void BitmapObject::translate(Vector2D vec) {
  texture.move(vec.x, vec.y);
}

void BitmapObject::scale(float sx, float sy, Vector2D origin) {
  texture.setOrigin(origin.x, origin.y);
  texture.setScale(sx, sy);
}

void BitmapObject::draw(sf::RenderTarget *target) { 
  target->draw(texture);
}

