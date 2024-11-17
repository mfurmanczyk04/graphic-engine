#include "FallingObject.hpp"
#include "InputState.hpp"
#include "ObjectManager.hpp"
#include "Vector2D.hpp"

FallingObject::FallingObject(Vector2D startPos, float radius, float deathY)
    : position(startPos), radius(radius), deathY(deathY) {}

bool FallingObject::init(Initializer *initializer) {
  auto manager = initializer->getObjectManager();
  player = dynamic_cast<Player *>(manager->getFirstOfType(typeid(Player)));
  return true;
}

void FallingObject::translate(Vector2D vec) {
  position.x += vec.x;
  position.y += vec.y;
}

void FallingObject::scale(float sx, float sy, Vector2D origin) { radius *= sx; }

bool FallingObject::isTouchingPlayer() {
  Vector2D areaPosition = position;
  float areaRadius = radius;
  for (auto playerPosition : player->getCollisionPoints()) {
    float dx = playerPosition.x - areaPosition.x;
    float dy = playerPosition.y - areaPosition.y;
    float distanceSquared = dx * dx + dy * dy;
    if(distanceSquared <= areaRadius * areaRadius) {
      return true;
    }
  }
  return false;
}

void FallingObject::update(const InputState &input, ObjectManager *manager) {
  if(willDelete) {
    manager->removeObject(this);
    return;
  };

  this->translate({0, 4.0});
  if (position.y > deathY) {
    willDelete = true;
  }

  if (isTouchingPlayer()) {
    onTouchedPlayer(player);
  }


}

void FallingObject::rotate(float deg, Vector2D origin) { return; }
