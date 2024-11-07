#include "InputState.hpp"
#include <stdexcept>

bool InputState::isKeyDown(sf::Keyboard::Key key) const {
  try {
    return pressedKeys.at(key);
  } catch (std::out_of_range e) {
    return false;
  }
}

Vector2D InputState::getMousePos() const {
  return mousePos;
}

// setters - for engine to handle
void InputState::setKeyDown(sf::Keyboard::Key key) {
  pressedKeys[key] = true;
  
}
void InputState::setKeyUp(sf::Keyboard::Key key){
  pressedKeys[key] = false;
}

void InputState::setLeftClickDown(){
  buttons.left = true;
}

void InputState::setLeftClickUp(){
  buttons.left = false;
}

void InputState::setRightClickDown(){
  buttons.right = true;
}

void InputState::setRightClickUp(){
  buttons.right = false;
}

void InputState::setMousePos(float x, float y){
  mousePos.x = x;
  mousePos.y = y;
}

