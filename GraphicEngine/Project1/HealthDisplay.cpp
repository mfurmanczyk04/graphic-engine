#include "HealthDisplay.hpp"
#include "Vector2D.hpp"

HealthDisplay::HealthDisplay(Vector2D position, Player *playerInstance) 
: heartBitmap(position, "heart_full"), position(position), playerInstance(playerInstance)
{}

bool HealthDisplay::init(Initializer *initializer) {
  return heartBitmap.init(initializer);
}

void HealthDisplay::draw(Renderer *rp) {
  auto target = rp->getRenderTarget();
  auto health = playerInstance->getHealth();
  for (int i = 0; i < health; i++) {
    heartBitmap.translate({i*64.0f, 0});
    heartBitmap.draw(target);
    heartBitmap.translate({-i*64.0f, 0});
  }
}
