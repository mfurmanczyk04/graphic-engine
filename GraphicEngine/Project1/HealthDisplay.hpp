#ifndef HEALTHDISPLAY_CPP
#define HEALTHDISPLAY_CPP

#include "BitmapObject.hpp"
#include "DrawableObject.hpp"
#include "Player.hpp"
#include "Vector2D.hpp"

class HealthDisplay : public DrawableObject {
public:
  HealthDisplay(Vector2D position, Player *playerInstance);
  void draw(Renderer *rp) override;
  bool init(Initializer *initializer) override;
private:
  Player *playerInstance;
  BitmapObject heartBitmap;
  Vector2D position;
};

#endif
