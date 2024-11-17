#ifndef ROCKSPAWNER_HPP
#define ROCKSPAWNER_HPP

#include "Rock.hpp"
#include "UpdatableObject.hpp"
#include <random>

class RockSpawner : public UpdatableObject {
public:
  RockSpawner(std::uniform_real_distribution<> spawnRange,
              std::uniform_real_distribution<> sizeRange, float deathY)
      : spawnRange(spawnRange), sizeRange(sizeRange) {}
  void update(const InputState &input, ObjectManager *manager) override {
    cooldown--;
    if (cooldown == 0) {
      float spawnX = spawnRange(rng);
      float radius = sizeRange(rng);
      manager->addObject(new Rock({spawnX, -radius}, radius, deathY));
      cooldown = cooldownAmount;
    }
  }

private:
  std::mt19937 rng;
  std::uniform_real_distribution<> spawnRange;
  std::uniform_real_distribution<> sizeRange;
  unsigned const cooldownAmount = 30;
  unsigned cooldown = cooldownAmount;
  float deathY;
};

#endif
