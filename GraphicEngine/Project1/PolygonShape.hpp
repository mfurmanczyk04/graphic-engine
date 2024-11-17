#ifndef POLYGONSHAPE_HPP
#define POLYGONSHAPE_HPP
#include "ShapeObject.hpp"
#include "TransformableObject.hpp"
class PolygonShape : public ShapeObject, public TransformableObject {
public:
  PolygonShape(const std::vector<Vector2D> &verts, sf::Color color, sf::Color fillColor = sf::Color::Transparent);
  virtual void translate(Vector2D vec) override;
  virtual void rotate(float deg, Vector2D origin) override;
  virtual void scale(float sx, float sy, Vector2D origin) override;
  void draw(PrimitiveRenderer *pr) override;
private:
  sf::Color color;
  sf::Color fillColor;
  std::vector<Vector2D> verts;
};

#endif
