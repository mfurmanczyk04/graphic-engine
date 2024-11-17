// main.cpp
#include "Engine.hpp"
#include "Player.hpp"
#include "RockSpawner.hpp"

int main()
{
  Engine engine;


  const unsigned GAME_WIDTH = 1280;
  const unsigned GAME_HEIGHT = 720;


  if (engine.init()) {
    auto handler = engine.getBitmapHandler();
    handler->loadFromFile("player_up", "./assets/player_up.png");
    handler->loadFromFile("player_down", "./assets/player_down.png");
    handler->loadFromFile("player_left", "./assets/player_left.png");
    handler->loadFromFile("player_right", "./assets/player_right.png");


    engine.setGraphicsMode(false, sf::VideoMode(GAME_WIDTH, GAME_HEIGHT));
    engine.setParameters(60, true, true);

    engine.addObject(new Player({(float)GAME_WIDTH / 2.0, GAME_HEIGHT - 20.0}));
    engine.addObject(new RockSpawner(
      std::uniform_real_distribution(0.0, (double)GAME_WIDTH),
      std::uniform_real_distribution(10.0, 20.0), 20.0));

    engine.run();
  }

  return 0;
}
