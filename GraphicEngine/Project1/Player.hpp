#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "BitmapHandler.hpp"
#include "BitmapObject.hpp"
#include "DrawableObject.hpp"
#include "TransformableObject.hpp"
#include "UpdatableObject.hpp"
#include "Vector2D.hpp"

class Player : public DrawableObject, public TransformableObject, public UpdatableObject {
public:
  Player(Vector2D pos, BitmapHandler *bitmapHandler) :  position(pos.x, pos.y), sprite(pos, *bitmapHandler->getTexture("player")) {}
  
  void update(const InputState &input) override {
    Vector2D inputV = Vector2D(0,0);
    if (input.isKeyDown(sf::Keyboard::Key::W)) {
      inputV.y -= 1;
    }
    if (input.isKeyDown(sf::Keyboard::Key::S)) {
      inputV.y += 1;
    }
    if (input.isKeyDown(sf::Keyboard::Key::A)) {
      inputV.x -= 1;
    }
    if (input.isKeyDown(sf::Keyboard::Key::D)) {
      inputV.x += 1;
    }
    translate(inputV);
  }

  void translate(Vector2D vec) override {
    position.x += vec.x;
    position.y += vec.y;
    sprite.translate(vec);
  }

  void rotate(float deg, Vector2D origin) override {return;}
  void scale(float sx, float sy, Vector2D origin) override {return;}

  void draw(Renderer *rp) override { 
    sprite.draw(rp);
  }

private:
  Vector2D position;
  BitmapObject sprite;
};

#endif
