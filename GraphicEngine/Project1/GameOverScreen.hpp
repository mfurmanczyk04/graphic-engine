#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP
#include "BitmapObject.hpp"


class GameOverScreen : public BitmapObject {
public:
  GameOverScreen() : BitmapObject({0,0}, "game_over") {};
  
};
#endif

