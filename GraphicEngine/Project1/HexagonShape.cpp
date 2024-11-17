#include "HexagonShape.hpp"

std::vector<Vector2D> HexagonShape::generateHexagonVertices(Vector2D center, float radius)
{
  std::vector<Vector2D> vertices;
  float angleStep = M_PI / 3;  // 60 degrees in radians

  // Generate 6 vertices for the hexagon
  for (int i = 0; i < 6; ++i) {
    float angle = i * angleStep;
    float x = center.x + radius * std::cos(angle);
    float y = center.y + radius * std::sin(angle);
    vertices.push_back(Vector2D(x, y));
  }

  return vertices;
}
