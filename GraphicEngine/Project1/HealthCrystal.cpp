#include "HealthCrystal.hpp"
#include "FallingObject.hpp"
#include "HexagonShape.hpp"

HealthCrystal::HealthCrystal(Vector2D startPos, float radius, float deathY)
: FallingObject(startPos, radius, deathY),
  shape(startPos, radius, sf::Color::Green),
  center(startPos)
{ }


void HealthCrystal::translate(Vector2D vec) {
  FallingObject::translate(vec);
  shape.translate(vec);
  center.x += vec.x;
  center.y += vec.y;
}

void HealthCrystal::scale(float sx, float sy, Vector2D origin) {
  FallingObject::scale(sx, sy, origin);
  shape.scale(sx, sy, origin);
}

void HealthCrystal::rotate(float deg, Vector2D origin) {
  FallingObject::rotate(deg, origin);
  shape.rotate(deg, origin);
}

void HealthCrystal::draw(PrimitiveRenderer *pr) {
  return shape.draw(pr);
}

void HealthCrystal::onTouchedPlayer(Player *player) {
  player->heal();
  willDelete = true;
}


void HealthCrystal::update(const InputState &input, ObjectManager *manager) {
  FallingObject::update(input, manager);
  shape.rotate(1, center);

}
