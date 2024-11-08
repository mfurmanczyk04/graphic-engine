#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "ShapeObject.hpp"
#include "TransformableObject.hpp"
#include "Vector2D.hpp"

class Circle : public ShapeObject, public TransformableObject {
public:
  void translate(Vector2D vec) override;
  void setPosition(Vector2D pos) override;
  void rotate(float deg, Vector2D origin) override;
  void scale(float sx, float sy, Vector2D origin) override;
  void draw(PrimitiveRenderer *pr) override;
  Circle(Vector2D position, float radius, sf::Color color, sf::Color fillColor = sf::Color::Transparent);
private:
  Vector2D position;
  float radius;
  sf::Color color;
  sf::Color fillColor;
};


#endif
