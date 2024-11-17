#ifndef HEXAGONSHAPE_HPP
#define HEXAGONSHAPE_HPP
#include <cmath>
#include <vector>
#include "PolygonShape.hpp"

class HexagonShape : public PolygonShape {
public:
    HexagonShape(Vector2D center, float radius, sf::Color color, sf::Color fillColor = sf::Color::Transparent)
        : PolygonShape(generateHexagonVertices(center, radius), color, fillColor) {}

private:
    std::vector<Vector2D> generateHexagonVertices(Vector2D center, float radius);
};

#endif
