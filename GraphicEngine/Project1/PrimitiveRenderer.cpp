#include "PrimitiveRenderer.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>


sf::Color sfColorFromColor(Color color) {
  return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
}

const float PI = 3.14159f;
const float CIRCLE_STEP = 0.005f;

void PrimitiveRenderer::drawEllipsis(float x, float y, float rx, float ry) {
  std::vector<Vector2D> ellipsisPoints;
  for (float alpha = 0.0f; alpha <= PI/2; alpha += CIRCLE_STEP)  {
    Vector2D point(rx*std::cos(alpha), ry*std::sin(alpha));
    ellipsisPoints.push_back(point);
  }
  for (Vector2D point : ellipsisPoints) {
    setPixel(point.getX()+x,point.getY()+y);
    setPixel(-point.getX()+x,point.getY()+y);
    setPixel(point.getX()+x,-point.getY()+y);
    setPixel(-point.getX()+x,-point.getY()+y);
  }
}

struct ScreenPixel {
  unsigned int x;
  unsigned int y;
  sf::Color color;
};


/*
void PrimitiveRenderer::boundryFill(unsigned int x, unsigned int y, Color fillColor, Color backgroundColor, bool moore) {
  sf::Sprite outputSprite;
  sf::Texture outputTexture;

  sf::Color _fillColor = sfColorFromColor(fillColor);
  sf::Color _backgroundColor = sfColorFromColor(backgroundColor);

  sf::Image image = _rt->getTexture().copyToImage();
  std::vector<ScreenPixel> pixels;
  pixels.push_back(ScreenPixel {
    x,
    y,
    image.getPixel(x, y)
  });

  while (!pixels.empty()) {
    ScreenPixel p = pixels[pixels.size() - 1];
    if(p.x < 0) return;
    if(p.y < 0) return;
    if(p.x >= 800) return;
    if(p.y >= 600) return;
    pixels.pop_back();
    if (p.color == _fillColor)
      continue;
    if (p.color != _backgroundColor)
      continue;
    p.color = _fillColor;
    image.setPixel(p.x, p.y, p.color);
    if(p.x+1 < 800) {
      pixels.push_back(ScreenPixel { p.x+1, p.y, image.getPixel(p.x+1, p.y) });
    }
    if(p.x-1 >= 0) {
      pixels.push_back(ScreenPixel { p.x-1, p.y, image.getPixel(p.x-1, p.y) });
    }
    if(p.y+1 < 600) {
    pixels.push_back(ScreenPixel { p.x, p.y+1, image.getPixel(p.x, p.y+1) });
    }
    if(p.y-1 >= 0) {
    pixels.push_back(ScreenPixel { p.x, p.y-1, image.getPixel(p.x, p.y-1) });
    }
  }
  outputTexture.loadFromImage(image);
  outputSprite.setTexture(outputTexture);
  _rt->draw(outputSprite);
}
*/


std::vector<Vector2D> PrimitiveRenderer::boundryFill(const std::vector<Vector2D> &circVerts, Vector2D origin) {
  std::vector<Vector2D> stack;
  std::vector<Vector2D> drawnStack;
  stack.push_back(origin);
  while (!stack.empty()) {
    Vector2D p = stack.back();
    stack.pop_back();

    bool collided = false;
    for (auto circP : circVerts) {
      if (p.getX() == circP.getX() && p.getY() == circP.getY()) {
        drawnStack.push_back(p);
        collided = true;
        break;
      }
    }
    if (collided) {
      continue;
    }
  
    stack.push_back(Vector2D(p.getX(), p.getY()-1));
    stack.push_back(Vector2D(p.getX(), p.getY()+1));
    stack.push_back(Vector2D(p.getX()-1, p.getY()));
    stack.push_back(Vector2D(p.getX()+1, p.getY()));
  }
  
  return drawnStack;
}

void PrimitiveRenderer::drawCircle(float x, float y, float radius) {
  std::vector<Vector2D> circlePoints;
  for (float alpha = 0.0f; alpha <= PI/2; alpha += CIRCLE_STEP)  {
    Vector2D point(radius*std::cos(alpha), radius*std::sin(alpha));
    circlePoints.push_back(point);
  }
  

  for (Vector2D point : circlePoints) {
    setPixel(point.getX()+x,point.getY()+y);
    setPixel(-point.getX()+x,point.getY()+y);
    setPixel(point.getX()+x,-point.getY()+y);
    setPixel(-point.getX()+x,-point.getY()+y);
  }
}

void PrimitiveRenderer::drawCircleBuiltin(float x, float y, float radius) {
  sf::CircleShape circleShape;
  circleShape.setPosition(x, y);
  circleShape.setFillColor(_color);
  circleShape.setRadius(radius);
  _rt->draw(circleShape);
}


void PrimitiveRenderer::setPixel(float x, float y) {
  sf::Vertex vert = sf::Vertex(sf::Vector2(x,y), _color);
  _rt->draw(&vert, 1, sf::Points);
}
void PrimitiveRenderer::setPixels(const std::vector<Vector2D> &verts) {
  for (auto vert : verts) {
    setPixel(vert.getX(), vert.getY());
  }
}


void PrimitiveRenderer::setColor(Color color) {
  _color = sfColorFromColor(color);
}

void PrimitiveRenderer::drawLineBuiltin(float x0, float y0, float x1, float y1) {
  sf::Vertex lineVerts[2] = {
    sf::Vertex(sf::Vector2(x0, y0), _color),
    sf::Vertex(sf::Vector2(x1, y1), _color),
  };
  _rt->draw(lineVerts, 2, sf::Lines);
}

void PrimitiveRenderer::drawPolyLine(const std::vector<Vector2D> &verts) {
  if (verts.size() < 2)  return;
  for(int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].getX();
    auto y0 = verts[i].getY();
    auto x1 = verts[i+1].getX();
    auto y1 = verts[i+1].getY();
    drawLine(x0,y0,x1,y1);
  }
}


bool areVertsCrossing(const std::vector<Vector2D> &verts);

void PrimitiveRenderer::drawPoly(std::vector<Vector2D> &verts, bool full) {
  if (verts.size() < 2)  return;
  verts.push_back(verts.front());
  if(areVertsCrossing(verts)) {
    return;
  }
  for(int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].getX();
    auto y0 = verts[i].getY();
    auto x1 = verts[i+1].getX();
    auto y1 = verts[i+1].getY();
    drawLine(x0,y0,x1,y1);
  }
}



// Given three collinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Vector2D p, Vector2D q, Vector2D r) 
{ 
    if (q.getX() <= std::max(p.getX(), r.getX()) && q.getX() >= std::min(p.getX(), r.getX()) && 
        q.getY() <= std::max(p.getY(), r.getY()) && q.getY() >= std::min(p.getY(), r.getY())) 
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
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) - 
              (q.getX() - p.getX()) * (r.getY() - q.getY()); 
  
    if (val == 0) return 0;  // collinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
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


void PrimitiveRenderer::drawLine(float x0, float y0, float x1, float y1) {
  float deltaX = x1 - x0; // 600 - 700 = -100
  float deltaY = y1 - y0; // 
  float m = deltaY / deltaX;

  float sy = std::min(y0, y1);
  float ey = std::max(y0, y1);
  float sx = std::min(x0, x1);
  float ex = std::max(x0, x1);

  std::vector<Vector2D> pts;

  if(std::abs(m) <= 1) {
    float nY = sy;
    for(float x = sx; x <= ex; x+=1) {
      pts.push_back(Vector2D(std::round(x),std::round(nY)));
      nY += m;
    }
  }
  else {
    m = deltaX / deltaY;
    float nX = sx;
    for(float y = sy; y <= ey; y+=1) {
      pts.push_back(Vector2D(std::round(nX),std::round(y)));
      nX += m;
    }
  }
  
  for (auto pt : pts) {
    setPixel(pt.getX(), pt.getY());
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
void PrimitiveRenderer::clearScreen() {
  _rt->clear(_color);
}


