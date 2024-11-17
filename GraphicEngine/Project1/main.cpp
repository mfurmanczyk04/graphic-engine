// main.cpp
#include "Engine.hpp"
#include "Player.hpp"

int main()
{
  Engine engine;

  if (engine.init()) {

    engine.setGraphicsMode(false, sf::VideoMode(1280, 720));
    engine.setParameters(60, true, true);
    auto handler = engine.getBitmapHandler();
    handler->loadFromFile("player", "./assets/player_up.png");
    Player *player = new Player({20.0, 20.0});
    engine.addObject(player);
    engine.run();
    delete player;
  }

  return 0;
}
