#include "PolygonShape.hpp"
#include <cmath>
#include <cwchar>

PolygonShape::PolygonShape(const std::vector<Vector2D> &verts, sf::Color color, sf::Color fillColor) 
: verts(verts), color(color), fillColor(fillColor)
{}

void PolygonShape::translate(Vector2D vec) {
    for (auto& vertex : verts) {
        vertex.x += vec.x;
        vertex.y += vec.y;
    }
}


void PolygonShape::rotate(float deg, Vector2D origin) {
    // Convert degrees to radians
    float rad = deg * M_PI / 180.0f;

    for (auto& vertex : verts) {
        float dx = vertex.x - origin.x;
        float dy = vertex.y - origin.y;

        // Rotate the vertex
        float newX = origin.x + (dx * std::cos(rad) - dy * std::sin(rad));
        float newY = origin.y + (dx * std::sin(rad) + dy * std::cos(rad));

        // Update the vertex
        vertex.x = newX;
        vertex.y = newY;
    }
}


void PolygonShape::scale(float sx, float sy, Vector2D origin) {
    for (auto& vertex : verts) {
        vertex.x = origin.x + (vertex.x - origin.x) * sx;
        vertex.y = origin.y + (vertex.y - origin.y) * sy;
    }
}

void PolygonShape::draw(PrimitiveRenderer *pr) {
  return pr->drawPoly(verts, color, fillColor);
}
