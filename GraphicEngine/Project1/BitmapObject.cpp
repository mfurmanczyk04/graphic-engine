#include "BitmapObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>


BitmapObject::BitmapObject(Vector2D position, const std::string& textureName) 
: textureName(textureName),
  position(position) {}

bool BitmapObject::init(Initializer *initalizer) {
  auto handler = initalizer->getBitmapHandler();
  auto texture = handler->getTexture(textureName);
  if(!texture) {
    return false;
  }

  sprite = new sf::Sprite(*texture);
  if(!sprite) return false;
  sprite->setPosition(position.x, position.y);
  return true;
}

void BitmapObject::rotate(float deg, Vector2D origin) {
  sprite->setOrigin(origin.x, origin.y);
  sprite->rotate(deg);
}

BitmapObject::~BitmapObject() {
  delete sprite;
}

void BitmapObject::translate(Vector2D vec) {
  sprite->move(vec.x, vec.y);
  position.x += vec.x;
  position.y += vec.y;
}

void BitmapObject::scale(float sx, float sy, Vector2D origin) {
  sprite->setOrigin(origin.x, origin.y);
  sprite->scale(sx, sy);
}

void BitmapObject::draw(sf::RenderTarget *target) { 
  target->draw(*sprite);
}

