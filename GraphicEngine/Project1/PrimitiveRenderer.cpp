#include "PrimitiveRenderer.hpp"
#include "ScreenPoint2D.hpp"
#include "Vector2D.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>


const float PI = 3.14159f;
const float CIRCLE_STEP = 0.001f;

void PrimitiveRenderer::setImage(sf::Image *image) {
  _output = image;
}

void PrimitiveRenderer::drawEllipsis(int x, int y, int rx, int ry, sf::Color color) {
  std::vector<Vector2D> ellipsisPoints;
  for (float alpha = 0.0f; alpha <= PI/2; alpha += CIRCLE_STEP)  {
    Vector2D point(rx*std::cos(alpha), ry*std::sin(alpha));
    ellipsisPoints.push_back(point);
  }

  for (Vector2D point : ellipsisPoints) {
    setPixel(+point.x+x, +point.y+y, color);
    setPixel(-point.x+x, +point.y+y, color);
    setPixel(+point.x+x, -point.y+y, color);
    setPixel(-point.x+x, -point.y+y, color);
  }
}

struct ScreenPixel {
  unsigned int x;
  unsigned int y;
  sf::Color color;
};


void PrimitiveRenderer::drawCircle(float x, float y, float radius, sf::Color color) {
  std::vector<Vector2D> circlePoints;
  for (float alpha = 0.0f; alpha <= PI/2; alpha += CIRCLE_STEP)  {
    Vector2D point(radius*std::cos(alpha), radius*std::sin(alpha));
    circlePoints.push_back(point);
  }
  for (Vector2D point : circlePoints) {
    setPixel(point.x+x,point.y+y  ,color);
    setPixel(-point.x+x,point.y+y ,color);
    setPixel(point.x+x,-point.y+y ,color);
    setPixel(-point.x+x,-point.y+y,color);
  }
}


void PrimitiveRenderer::setPixel(int x, int y, sf::Color color) {
  auto size = _output->getSize();
  if(x < 0 || y < 0 || x > size.x || y > size.y) {
    return;
  }
  _output->setPixel(x, y, color);
}

void PrimitiveRenderer::setPixels(const std::vector<Vector2D> &verts, sf::Color color) {
  for (auto vert : verts) {
    setPixel(vert.x, vert.y, color);
  }
}


void PrimitiveRenderer::drawPolyLine(const std::vector<Vector2D> &verts, sf::Color color) {
  if (verts.size() < 2)  return;
  for(int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].x;
    auto y0 = verts[i].y;
    auto x1 = verts[i+1].x;
    auto y1 = verts[i+1].y;
    drawLine(x0,y0,x1,y1, color);
  }
}

struct ScreenPoint {
  int x;
  int y;
  sf::Color color;
};

void PrimitiveRenderer::boundaryFill(int x, int y, sf::Color fillColor, sf::Color boundaryColor) {
  std::stack<ScreenPoint> stack;
  ScreenPoint origin{x, y, _output->getPixel(x, y)};
  stack.push(origin);
  while (!stack.empty()) {
    ScreenPoint p = stack.top();
    stack.pop();
    if (p.color == fillColor) {
       return;
    }
    if (p.color == boundaryColor) {
      p.color = fillColor;
      setPixel(p.x, p.y, fillColor);

    }
  }


}



bool areVertsCrossing(const std::vector<Vector2D> &verts);

void PrimitiveRenderer::drawPoly(std::vector<Vector2D> &verts,sf::Color color, bool full) {
  std::vector<ScreenPoint2D> pix;
  if (verts.size() < 2)  return;
  verts.push_back(verts.front());
  if(areVertsCrossing(verts)) {
    return;
  }
  for(int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].x;
    auto y0 = verts[i].y;
    auto x1 = verts[i+1].x;
    auto y1 = verts[i+1].y;
    drawLine(x0,y0,x1,y1, color);
  }
}

// Given three collinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Vector2D p, Vector2D q, Vector2D r) 
{ 
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
int orientation(Vector2D p, Vector2D q, Vector2D r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;  // collinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

bool doIntersect(Vector2D p1, Vector2D q1, Vector2D p2, Vector2D q2) 
{ 
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
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
     // p2, q2 and q1 are collinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false; // Doesn't fall in any of the above cases 
} 


void PrimitiveRenderer::drawLine(int x0, int y0, int x1, int y1, sf::Color color) {
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    // Check if the line is vertical
    if (deltaX == 0) {
        int sy = std::min(y0, y1);
        int ey = std::max(y0, y1);
        for (int y = sy; y <= ey; y += 1) {
            setPixel(std::round(x0), std::round(y), color);
        }
    } 
    else {
        int m = deltaY / deltaX;

        // Low slope case
        if (std::abs(m) <= 1) {
            int sy = std::min(y0, y1);
            int sx = std::min(x0, x1);
            int ex = std::max(x0, x1);
            int nY = y0 + m * (sx - x0);

            for (int x = sx; x <= ex; x += 1) {
                setPixel(std::round(x), std::round(nY), color);
                nY += m;
            }
        } 
        else {
            m = deltaX / deltaY;
            int sy = std::min(y0, y1);
            int ey = std::max(y0, y1);
            int nX = x0 + (sy - y0) * m;

            for (int y = sy; y <= ey; y += 1) {
                setPixel(std::round(nX), std::round(y), color);
                nX += m;
            }
        }
    }
}



bool areVertsCrossing(const std::vector<Vector2D> &verts) {
  if(verts.size() <= 3) return false;
  for(int i = 0; i <= verts.size() - 4; i+=4) {
    if(doIntersect(verts[i], verts[i+1], verts[i+2],verts[i+3])) {
      return true;
    }
  }
  return false;
}
