#ifndef ROCKSPAWNER_HPP
#define ROCKSPAWNER_HPP

#include "HealthCrystal.hpp"
#include "Rock.hpp"
#include "UpdatableObject.hpp"
#include <random>

class RockSpawner : public UpdatableObject {
public:
  RockSpawner(std::uniform_real_distribution<> spawnRange,
              std::uniform_real_distribution<> sizeRange, float deathY)
      : spawnRange(spawnRange), sizeRange(sizeRange), deathY(deathY) {}
  void update(const InputState &input, ObjectManager *manager) override {
    std::uniform_real_distribution<> floatRange(0.0, 1.0);

    cooldown--;
    if (cooldown == 0) {
      float spawnX = spawnRange(rng);
      float radius = sizeRange(rng);
      float healthCheck = floatRange(rng);
      if(healthCheck > 0.9)  {
        manager->addObject(new HealthCrystal({spawnX, -radius}, radius, deathY));
      }
      else {
        manager->addObject(new Rock({spawnX, -radius}, radius, deathY));
      }
      cooldown = cooldownAmount;
    }
  }

private:
  std::mt19937 rng;
  std::uniform_real_distribution<> spawnRange;
  std::uniform_real_distribution<> sizeRange;
  unsigned const cooldownAmount = 10;
  unsigned cooldown = cooldownAmount;
  float deathY;
};

#endif
