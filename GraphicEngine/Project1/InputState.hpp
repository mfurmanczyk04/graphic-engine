#ifndef INPUTSTATE_HPP
#define INPUTSTATE_HPP
#include "Vector2D.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>


struct MouseButtons {
  bool left;
  bool right;
  bool middle;
};

class InputState {
public:
  bool isKeyDown(sf::Keyboard::Key key) const;
  Vector2D getMousePos() const; 

  // setters - for engine to handle
  void setKeyDown(sf::Keyboard::Key key);
  void setKeyUp(sf::Keyboard::Key key);
  void setLeftClickDown();
  void setLeftClickUp();
  void setRightClickDown();
  void setRightClickUp();
  void setMousePos(float x, float y);
private:
  std::unordered_map<sf::Keyboard::Key, bool> pressedKeys;
  Vector2D mousePos{0, 0};
  MouseButtons buttons;
};
#endif
