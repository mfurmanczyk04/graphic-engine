#include "PrimitiveRenderer.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <cstdlib>
#include <iostream>

sf::Color sfColorFromColor(Color color) {
  return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
}

void PrimitiveRenderer::drawCircleBuiltin(float x, float y, float radius) {
  sf::CircleShape circleShape;
  circleShape.setPosition(x, y);
  circleShape.setFillColor(_color);
  circleShape.setRadius(radius);
  _window->draw(circleShape);
}


void PrimitiveRenderer::setPixel(float x, float y) {
  sf::Vertex vert = sf::Vertex(sf::Vector2(x,y), _color);
  _window->draw(&vert, 1, sf::Points);
}

void PrimitiveRenderer::setColor(Color color) {
  _color = sfColorFromColor(color);
}

void PrimitiveRenderer::drawLineBuiltin(float x0, float y0, float x1, float y1) {
  sf::Vertex lineVerts[2] = {
    sf::Vertex(sf::Vector2(x0, y0), _color),
    sf::Vertex(sf::Vector2(x1, y1), _color),
  };
  _window->draw(lineVerts, 2, sf::Lines);
}

void PrimitiveRenderer::drawLine(float x0, float y0, float x1, float y1) {
  float deltaX = x1 - x0;
  float deltaY = y1 - y0;
  float m = deltaY / deltaX;
  float sx, sy, ex, ey;
  if (deltaX > 0) {
    sx = x0;
    ex = x1;
  } else { //deltaX < 0
    sx = x1; // sx = 700
    ex = x0; // ex = 800
  }
  if (deltaY > 0) {
    sy = y0;
    ey = y1;
  } else {
    sy = y1;
    ey = y0;
  }

  if(std::abs(m) <= 1) {
    float nY = sy;
    for(float x = sx; x <= ex; x+=1) {
      setPixel(x, nY);
      nY += m;
    }
  }
  else {
    float nX = sx;
    for(float y = sy; y <= ey; y+=1) {
      setPixel(nX, y);
      nX += m;
    }
  }
}

void PrimitiveRenderer::clearScreen() {
  _window->clear(_color);
}


