#include "Rock.hpp"
#include "Circle.hpp"
#include "InputState.hpp"
#include "ObjectManager.hpp"
#include "PrimitiveRenderer.hpp"
#include "Vector2D.hpp"



void Rock::draw(PrimitiveRenderer *pr) {
  return circle->draw(pr);
}

Rock::Rock(Vector2D startPos, float radius, float deathY) : position(startPos), radius(radius), deathY(deathY) {
  circle = new Circle(startPos, radius, sf::Color::Red, sf::Color::White);
  circle->setPosition(startPos);
}

bool Rock::init(Initializer *initializer) {
  auto manager = initializer->getObjectManager();
  player = dynamic_cast<Player *>(manager->getFirstOfType(typeid(Player)));
  return true;
}

void Rock::translate(Vector2D vec) {
  position.x += vec.x;
  position.y += vec.y;
  circle->translate(vec);
}

void Rock::scale(float sx, float sy, Vector2D origin) {
  radius *= sx;
  circle->scale(sx, sx, origin);
}

void Rock::update(const InputState &input, ObjectManager *manager) {
  this->translate({0, 4.0});
  if (position.y > 1280) {
    manager->removeObject(this);
  }
}

void Rock::rotate(float deg, Vector2D origin) { return; }
