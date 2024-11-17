#ifndef HEALTHCRYSTAL_HPP
#define HEALTHCRYSTAL_HPP

#include "FallingObject.hpp"
#include "HexagonShape.hpp"

class HealthCrystal : public ShapeObject, public FallingObject {
public:
  HealthCrystal(Vector2D startPos, float radius, float deathY);
  void translate(Vector2D vec) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void rotate(float deg, Vector2D origin) override;
  void onTouchedPlayer(Player *player) override;
  void draw(PrimitiveRenderer *pr) override;
  void update(const InputState &input, ObjectManager *manager) override;
private:
  HexagonShape shape;
  Vector2D center;
};
#endif
