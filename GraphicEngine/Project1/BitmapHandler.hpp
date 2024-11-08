#ifndef BITMAPHANDLER_HPP
#define BITMAPHANDLER_HPP

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <unordered_map>

class BitmapHandler {
public:
  sf::Texture *createTexture(const std::string& name, const sf::Image& data);
  sf::Texture *loadFromFile(const std::string& name, const std::string &filename);
  void deleteTexture(const std::string& name);
  void cleanAllTextures();
  sf::Texture *getTexture(const std::string& name);
private:
  std::unordered_map<std::string, sf::Texture> loadedTextures;
};

#endif
