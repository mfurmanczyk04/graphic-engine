#include "Rock.hpp"
#include "CircleShape.hpp"
#include "FallingObject.hpp"
#include <iostream>

Rock::Rock(Vector2D startPos, float radius, float deathY)
    : rockColor(20, 20, 20), FallingObject(startPos, radius, deathY),
      circle(startPos, radius, rockColor, rockColor) {}

void Rock::translate(Vector2D vec) {
  FallingObject::translate(vec);
  circle.translate(vec);
}

void Rock::scale(float sx, float sy, Vector2D origin) {
  FallingObject::scale(sx, sy, origin);
  circle.scale(sx, sy, origin);
}

void Rock::draw(PrimitiveRenderer *pr) {
  return circle.draw(pr);
}

void Rock::onTouchedPlayer(Player *player) {
  player->hit();
}


