#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "BitmapObject.hpp"
#include "DrawableObject.hpp"
#include "Initializer.hpp"
#include "ObjectManager.hpp"
#include "TransformableObject.hpp"
#include "UpdatableObject.hpp"
#include "Vector2D.hpp"

class Player : public DrawableObject,
               public TransformableObject,
               public UpdatableObject {
public:
  Player(Vector2D pos);
  ~Player();
  void update(const InputState &input, ObjectManager *manager) override;
  bool init(Initializer *initializer) override;
  void translate(Vector2D vec) override;
  void rotate(float deg, Vector2D origin) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void draw(Renderer *rp) override;

private:
  Vector2D position;
  BitmapObject *leftSprite;
  BitmapObject *rightSprite;
  BitmapObject *upSprite;
  BitmapObject *downSprite;
  BitmapObject *currentSprite;
};

#endif
