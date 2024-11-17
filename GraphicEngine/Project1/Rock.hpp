#ifndef ROCK_HPP
#define ROCK_HPP
#include "CircleShape.hpp"
#include "FallingObject.hpp"
#include "ShapeObject.hpp"
#include "Vector2D.hpp"

class Rock : public FallingObject , public ShapeObject {
public:
  Rock(Vector2D startPos, float radius, float deathY);
  void draw(PrimitiveRenderer *pr) override;
  void translate(Vector2D vec) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void onTouchedPlayer(Player *player) override;
private:
  sf::Color rockColor;
  CircleShape circle;
};

#endif
