#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Point2D.hpp"
#include "ShapeObject.hpp"
#include "UpdatableObject.hpp"
#include "Vector2D.hpp"
class Player : public ShapeObject, public UpdatableObject {
public:
  void draw(PrimitiveRenderer *pr) override { shape.draw(pr); }
  Player(Vector2D pos)
      : position(pos.x, pos.y), shape(pos, sf::Color::Yellow) {} 
  
  void update(const InputState &input) override {
    if (input.isKeyDown(sf::Keyboard::Key::S)) {
      position.y += 1;
      shape.setPosition(position);
    }
  }

private:
  Vector2D position;
  Point2D shape;
};

#endif
