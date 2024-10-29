#include "PrimitiveRenderer.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>


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
    if(p.x >= 500) return;
    if(p.y >= 500) return;
    pixels.pop_back();
    if (p.color == _fillColor)
      continue;
    if (p.color != _backgroundColor)
      continue;
    p.color = _fillColor;
    image.setPixel(p.x, p.y, p.color);
    pixels.push_back(ScreenPixel { p.x+1, p.y, image.getPixel(p.x+1, p.y) });
    pixels.push_back(ScreenPixel { p.x-1, p.y, image.getPixel(p.x-1, p.y) });
    pixels.push_back(ScreenPixel { p.x, p.y+1, image.getPixel(p.x, p.y+1) });
    pixels.push_back(ScreenPixel { p.x, p.y-1, image.getPixel(p.x, p.y-1) });
  }

  outputTexture.loadFromImage(image);
  outputSprite.setTexture(outputTexture);
  _rt->draw(outputSprite);
  
  
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

void PrimitiveRenderer::drawPoly(std::vector<Vector2D> verts) {
  if (verts.size() < 2)  return;
  for(int i = 0; i <= verts.size() - 2; i++) {
    auto x0 = verts[i].getX();
    auto y0 = verts[i].getY();
    auto x1 = verts[i+1].getX();
    auto y1 = verts[i+1].getY();
    std::cout << "Drawing (" << x0 << ',' << y0 <<"), ("<<x1<<","<<y1<<")\n";
    drawLine(x0,y0,x1,y1);
  }
}


void PrimitiveRenderer::drawLine(float x0, float y0, float x1, float y1) {
  float deltaX = x1 - x0;
  float deltaY = y1 - y0;
  float m = deltaY / deltaX;
  if(std::abs(m) <= 1) {
    float nY = y0;
    for(float x = x0; x <= x1; x+=1) {
      setPixel(std::round(x),std::round(nY));
      nY += m;
    }
    std::cout << "Drawing m <= 1 (normal)" << '\n';
  }
  else {
    m = deltaX / deltaY;
    float nX = x0;
    for(float y = y0; y <= y1; y+=1) {
      setPixel(std::round(nX), std::round(y));
      nX += m;
    }
    std::cout << "Drawing m > 1 (not normal)" << '\n';
  }
}

void PrimitiveRenderer::clearScreen() {
  _rt->clear(_color);
}


