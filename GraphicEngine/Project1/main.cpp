// main.cpp
#include "Engine.hpp"
#include "HealthDisplay.hpp"
#include "Player.hpp"
#include "RockSpawner.hpp"

int main()
{
  Engine engine;


  const unsigned GAME_WIDTH = 1280;
  const unsigned GAME_HEIGHT = 720;


  if (engine.init()) {
    auto handler = engine.getBitmapHandler();
    handler->loadFromFile("player_hit", "./assets/player_hit.png");
    handler->loadFromFile("player_up", "./assets/player_up.png");
    handler->loadFromFile("player_down", "./assets/player_down.png");
    handler->loadFromFile("player_left", "./assets/player_left.png");
    handler->loadFromFile("player_right", "./assets/player_right.png");
    handler->loadFromFile("game_over", "./assets/game_over.png");
    handler->loadFromFile("heart_full", "./assets/heart_full.png");

    engine.setGraphicsMode(false, sf::VideoMode(GAME_WIDTH, GAME_HEIGHT));
    engine.setParameters(60, true, true);


    auto player = new Player({(float)GAME_WIDTH / 2.0, GAME_HEIGHT - 20.0}, {32.0, 32.0});
    engine.addObject(player);
    engine.addObject(new HealthDisplay({40.0f, GAME_HEIGHT - 72.0f}, player));
    engine.addObject(new RockSpawner(
      std::uniform_real_distribution<double>(0.0, (double)GAME_WIDTH),
      std::uniform_real_distribution<double>(10.0, 20.0), 
      GAME_HEIGHT));

    engine.run();
  }

  return 0;
}
