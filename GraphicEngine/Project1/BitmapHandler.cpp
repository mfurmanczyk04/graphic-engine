#include "BitmapHandler.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>


sf::Texture *BitmapHandler::createTexture(const std::string& name, const sf::Image &data) {
  sf::Texture tex; 
  tex.loadFromImage(data);
  loadedTextures[name] = tex;
  return &loadedTextures[name];
}

sf::Texture *BitmapHandler::loadFromFile(const std::string& name, const std::string &filename) {
  sf::Texture tex;
  tex.loadFromFile(filename);
  loadedTextures[name] = tex;
  return &loadedTextures[name];
}

void BitmapHandler::deleteTexture(const std::string& name) {
  loadedTextures.erase(name);
}

void BitmapHandler::cleanAllTextures() {
  loadedTextures.clear();
}

sf::Texture *BitmapHandler::getTexture(const std::string& name) {
  try {
    return &loadedTextures.at(name);
  } catch (std::out_of_range e) {
    return nullptr;
  }
}

