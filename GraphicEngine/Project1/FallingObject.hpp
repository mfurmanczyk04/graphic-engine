#ifndef FALLINGOBJECT_HPP
#define FALLINGOBJECT_HPP
#include "Player.hpp"
#include "TransformableObject.hpp"
#include "UpdatableObject.hpp"
#include "Vector2D.hpp"

class FallingObject : public UpdatableObject, public TransformableObject {
public:
  FallingObject(Vector2D startPos, float radius, float deathY);

  virtual bool init(Initializer *initializer) override;
  virtual void translate(Vector2D vec) override;
  virtual void scale(float sx, float sy, Vector2D origin) override;
  virtual void rotate(float deg, Vector2D origin) override;
  virtual void update(const InputState &input, ObjectManager *manager) override;
  virtual void onTouchedPlayer(Player *player) = 0;
protected:
  bool willDelete = false;
private:
  bool isTouchingPlayer();
  Player *player;
  Vector2D position;
  float radius;
  float deathY;
};

#endif
