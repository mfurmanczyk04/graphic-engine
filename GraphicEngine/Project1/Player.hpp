#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "BitmapObject.hpp"
#include "DrawableObject.hpp"
#include "Initializer.hpp"
#include "ObjectManager.hpp"
#include "TransformableObject.hpp"
#include "UpdatableObject.hpp"
#include "Vector2D.hpp"
#include <array>

class Player : public DrawableObject,
               public TransformableObject,
               public UpdatableObject {
public:
  Player(Vector2D pos, Vector2D size);
  ~Player();
  void update(const InputState &input, ObjectManager *manager) override;
  bool init(Initializer *initializer) override;
  void translate(Vector2D vec) override;
  void rotate(float deg, Vector2D origin) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void draw(Renderer *rp) override;
  Vector2D getPosition() const { 
    return {position.x, position.y};
  }
  void hit();
  void heal();
  int getHealth() const;
  int getMaxHealth() const;
  std::array<Vector2D, 5> getCollisionPoints() const;
private:
  Vector2D position;
  Vector2D size;
  int hitCooldown = 0;
  int hitCooldownAmount = 60;
  /* float hitRadius = 4; */
  int maxHealth = 3;
  int health = maxHealth;
  BitmapObject *leftSprite = new BitmapObject(position, "player_left");
  BitmapObject *rightSprite = new BitmapObject(position, "player_right");
  BitmapObject *upSprite = new BitmapObject(position, "player_up");
  BitmapObject *downSprite = new BitmapObject(position, "player_down");
  BitmapObject *hitSprite = new BitmapObject(position, "player_hit");
  BitmapObject *currentSprite;
};

#endif
