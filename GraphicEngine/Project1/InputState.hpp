#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
class InputState {
  std::unordered_map<sf::Keyboard::Key, bool> _pressedKeys;
  bool isKeyPressed(sf::Keyboard::Key key);
};
