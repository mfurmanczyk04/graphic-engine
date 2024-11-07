#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Circle.hpp"
#include "ShapeObject.hpp"
#include "TransformableObject.hpp"
#include "UpdatableObject.hpp"
#include "Vector2D.hpp"
class Player : public ShapeObject, public UpdatableObject, public TransformableObject {
public:
  void draw(PrimitiveRenderer *pr) override { bodyShape.draw(pr); headShape.draw(pr); }
  Player(Vector2D pos)
      : 
    position(pos.x, pos.y),
    headShape(pos, 30.0, sf::Color::White, sf::Color::Yellow),
    bodyShape({pos.x, pos.y+80}, 40.0, sf::Color::White, sf::Color::Yellow) {} 
  
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
    headShape.translate(vec);
    bodyShape.translate(vec);
  }

  void setPosition(Vector2D pos) override { position = pos; }
  void rotate(float deg, Vector2D origin) override {return;}
  void scale(float sx, float sy, Vector2D origin) override {return;}

private:
  Vector2D position;
  Circle headShape;
  Circle bodyShape;
};

#endif
