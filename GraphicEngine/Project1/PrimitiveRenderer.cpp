#include "PrimitiveRenderer.hpp"
#include "ScreenPoint2D.hpp"
#include "Vector2D.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <vector>

const float PI = 3.14159f;
const float CIRCLE_STEP = 0.001f;

void PrimitiveRenderer::setImage(sf::Image *image) { _output = image; }

void PrimitiveRenderer::drawEllipsis(float x, float y, float rx, float ry,
                                     sf::Color color, sf::Color fill) {
  std::vector<Vector2D> ellipsisPoints;
  for (float alpha = 0.0f; alpha <= PI / 2; alpha += CIRCLE_STEP) {
    Vector2D point(rx * std::cos(alpha), ry * std::sin(alpha));
    ellipsisPoints.push_back(point);
  }

  for (Vector2D point : ellipsisPoints) {
    setPixel(+point.x + x, +point.y + y, color);
    setPixel(-point.x + x, +point.y + y, color);
    setPixel(+point.x + x, -point.y + y, color);
    setPixel(-point.x + x, -point.y + y, color);
  }
  if (fill.toInteger() > 0) {
    boundaryFill(x, y, color, fill);
  }
}

struct ScreenPixel {
  unsigned int x;
  unsigned int y;
  sf::Color color;
};

void PrimitiveRenderer::drawRect(float x, float y, float w, float h,
                                 sf::Color color, sf::Color fill) {
  drawLine(x, y, x + w, y, color);
  drawLine(x + w, y, x + w, y + w, color);
  drawLine(x + w, y + w, x, y + w, color);
  drawLine(x, y + w, x, y, color);
  if (fill.toInteger() > 0) {
    boundaryFill(x + 1, y + 1, color, fill);
  }
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius,
                                   sf::Color color, sf::Color fill) {
  std::vector<Vector2D> circlePoints;
  for (float alpha = 0.0f; alpha <= PI / 2; alpha += CIRCLE_STEP) {
    Vector2D point(radius * std::cos(alpha), radius * std::sin(alpha));
    circlePoints.push_back(point);
  }
  for (Vector2D point : circlePoints) {
    setPixel(point.x + x, point.y + y, color);
    setPixel(-point.x + x, point.y + y, color);
    setPixel(point.x + x, -point.y + y, color);
    setPixel(-point.x + x, -point.y + y, color);
  }
  if (fill.toInteger() > 0) {
    boundaryFill(x, y, color, fill);
  }
}

bool PrimitiveRenderer::isPixelInBounds(int x, int y) {
  return x >= 0 && y >= 0 && x < _output->getSize().x &&
         y < _output->getSize().y;
}

void PrimitiveRenderer::setPixel(int x, int y, sf::Color color) {
  if (isPixelInBounds(x, y)) {
    _output->setPixel(x, y, color);
  }
}

void PrimitiveRenderer::setPixels(const std::vector<Vector2D> &verts,
                                  sf::Color color) {
  for (auto vert : verts) {
    setPixel(vert.x, vert.y, color);
  }
}

void PrimitiveRenderer::drawPolyLine(const std::vector<Vector2D> &verts,
                                     sf::Color color) {
  if (verts.size() < 2)
    return;
  for (int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].x;
    auto y0 = verts[i].y;
    auto x1 = verts[i + 1].x;
    auto y1 = verts[i + 1].y;
    drawLine(x0, y0, x1, y1, color);
  }
}

void PrimitiveRenderer::boundaryFill(int x, int y, sf::Color boundaryColor,
                                     sf::Color fillColor) {
  if (!_output || !isPixelInBounds(x, y))
    return;

  std::stack<ScreenPoint2D> stack;
  stack.push({x, y});

  while (!stack.empty()) {
    ScreenPoint2D p = stack.top();
    stack.pop();

    // Check bounds for current pixel coordinates
    if (!isPixelInBounds(p.x, p.y))
      continue;

    // Get color of the current pixel from _output image
    sf::Color color = _output->getPixel(p.x, p.y);
    // Skip if the pixel is already the fill color or if it's a boundary color
    if (color == fillColor || color == boundaryColor)
      continue;
    // Fill the pixel with the fill color
    setPixel(p.x, p.y, fillColor);

    // Push neighboring pixels onto the stack for further processing
    stack.push({p.x, p.y - 1});
    stack.push({p.x, p.y + 1});
    stack.push({p.x - 1, p.y});
    stack.push({p.x + 1, p.y});
  }
}

bool areVertsCrossing(const std::vector<Vector2D> &verts);

void PrimitiveRenderer::drawPoly(std::vector<Vector2D> verts, sf::Color color,
                                 sf::Color fill) {
  if (verts.size() < 2)
    return;
  if (areVertsCrossing(verts)) { return; }
  verts.push_back(verts.front());
  for (int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].x;
    auto y0 = verts[i].y;
    auto x1 = verts[i + 1].x;
    auto y1 = verts[i + 1].y;
    drawLine(x0, y0, x1, y1, color);
  }
  if (fill.toInteger() > 0) {
    float sumX = 0.0f;
    float sumY = 0.0f;

    for (const auto& vertex : verts) {
        sumX += vertex.x;
        sumY += vertex.y;
    }
    float centerX = sumX / verts.size();
    float centerY = sumY / verts.size();
    std::cout << "Center: " << centerX << ", " << centerY << std::endl;
    boundaryFill(80.0, 80.0, color, fill);
  }
}

// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Vector2D p, Vector2D q, Vector2D r) {
  if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
      q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
    return true;
  return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Vector2D p, Vector2D q, Vector2D r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0)
    return 0;               // collinear
  return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doIntersect(Vector2D p1, Vector2D q1, Vector2D p2, Vector2D q2) {
  // Find the four orientations needed for general and
  // special cases
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  // General case
  if (o1 != o2 && o3 != o4)
    return true;
  // Special Cases
  // p1, q1 and p2 are collinear and p2 lies on segment p1q1
  if (o1 == 0 && onSegment(p1, p2, q1))
    return true;
  // p1, q1 and q2 are collinear and q2 lies on segment p1q1
  if (o2 == 0 && onSegment(p1, q2, q1))
    return true;
  // p2, q2 and p1 are collinear and p1 lies on segment p2q2
  if (o3 == 0 && onSegment(p2, p1, q2))
    return true;
  // p2, q2 and q1 are collinear and q1 lies on segment p2q2
  if (o4 == 0 && onSegment(p2, q1, q2))
    return true;
  return false; // Doesn't fall in any of the above cases
}

void PrimitiveRenderer::drawLine(float x0, float y0, float x1, float y1,
                                 sf::Color color) {
  float deltaX = x1 - x0;
  float deltaY = y1 - y0;
  // Check if the line is vertical
  if (deltaX == 0) {
    float sy = std::min(y0, y1);
    float ey = std::max(y0, y1);
    for (float y = sy; y <= ey; y += 1) {
      setPixel(std::round(x0), std::round(y), color);
    }
  } else {
    float m = deltaY / deltaX;

    // Low slope case
    if (std::abs(m) <= 1) {
      float sy = std::min(y0, y1);
      float sx = std::min(x0, x1);
      float ex = std::max(x0, x1);
      float nY = y0 + m * (sx - x0);

      for (float x = sx; x <= ex; x += 1) {
        setPixel(std::round(x), std::round(nY), color);
        nY += m;
      }
    } else {
      m = deltaX / deltaY;
      float sy = std::min(y0, y1);
      float ey = std::max(y0, y1);
      float nX = x0 + (sy - y0) * m;

      for (float y = sy; y <= ey; y += 1) {
        setPixel(std::round(nX), std::round(y), color);
        nX += m;
      }
    }
  }
}

bool areVertsCrossing(const std::vector<Vector2D> &verts) {
  if (verts.size() <= 3)
    return false;
  for (int i = 0; i <= verts.size() - 4; i += 4) {
    if (doIntersect(verts[i], verts[i + 1], verts[i + 2], verts[i + 3])) {
      return true;
    }
  }
  return false;
}
