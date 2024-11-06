#include "Vector2D.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
class InputState {
public:
  bool isKeyPressed(sf::Keyboard::Key key);
private:
  std::unordered_map<sf::Keyboard::Key, bool> _pressedKeys;
  Vector2D _mousePos;
};
