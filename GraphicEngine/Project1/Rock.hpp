#ifndef ROCK_HPP
#define ROCK_HPP
#include "Player.hpp"
#include "ShapeObject.hpp"
#include "TransformableObject.hpp"
#include "UpdatableObject.hpp"
#include "Circle.hpp"
#include "Vector2D.hpp"

class Rock : public ShapeObject, public UpdatableObject, public TransformableObject {
public:
  Rock(Vector2D startPos, float radius, float deathY);

  void draw(PrimitiveRenderer *pr) override;
  bool init(Initializer *initializer) override;
  void translate(Vector2D vec) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void rotate(float deg, Vector2D origin) override;
  void update(const InputState &input, ObjectManager *manager) override;
private:
  Player *player;
  Circle *circle;
  Vector2D position;
  float radius;
  float deathY;
};

#endif
