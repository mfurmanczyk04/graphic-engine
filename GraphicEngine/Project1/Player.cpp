#include "Player.hpp"
#include "GameOverScreen.hpp"
#include "Vector2D.hpp"
#include <algorithm>
#include <array>

Player::Player(Vector2D pos, Vector2D size) : position(pos), size(size) {}
Player::~Player() {
  delete leftSprite;
  delete rightSprite;
  delete upSprite;
  delete downSprite;
  delete hitSprite;
}

void Player::hit() {
  if(hitCooldown > 0) { return; }
  health--;
  hitCooldown = hitCooldownAmount;
}

void Player::heal() {
  health = std::min(health + 1, maxHealth);
}


int Player::getHealth() const {
  return health;
}

int Player::getMaxHealth() const {
  return health;
}
void Player::update(const InputState &input, ObjectManager *manager) {
  if(currentSprite == hitSprite) {
    currentSprite = upSprite;
  }

  if (health <= 0) {
    manager->addObject(new GameOverScreen());
    return;
  }
  auto inputV = Vector2D(0, 0);
  if (input.isKeyDown(sf::Keyboard::Key::W)) {
    inputV.y -= 2;
    currentSprite = upSprite;
  }
  if (input.isKeyDown(sf::Keyboard::Key::S)) {
    inputV.y += 2;
    currentSprite = downSprite;
  }
  if (input.isKeyDown(sf::Keyboard::Key::A)) {
    inputV.x -= 2;
    currentSprite = leftSprite;
  }
  if (input.isKeyDown(sf::Keyboard::Key::D)) {
    inputV.x += 2;
    currentSprite = rightSprite;
  }
  if(hitCooldown > 0) {
    hitCooldown--;
    currentSprite = hitSprite;
  }
  translate(inputV);
}

bool Player::init(Initializer *initializer) {
  auto handler = initializer->getBitmapHandler();

  leftSprite->init(initializer);
  rightSprite->init(initializer);
  upSprite->init(initializer);
  downSprite->init(initializer);
  hitSprite->init(initializer);

  currentSprite = upSprite;
  return true;
}

void Player::translate(Vector2D vec) {
  position.x += vec.x;
  position.y += vec.y;
  leftSprite->translate(vec);
  rightSprite->translate(vec);
  upSprite->translate(vec);
  downSprite->translate(vec);
  hitSprite->translate(vec);
}


std::array<Vector2D, 5> Player::getCollisionPoints() const {
  std::array<Vector2D, 5> points{
    Vector2D(position.x,position.y),
    Vector2D(position.x+size.x,position.y),
    Vector2D(position.x+size.x,position.y+size.y),
    Vector2D(position.x,position.y+size.y),
    Vector2D(position.x+size.x/2,position.y+size.y/2)
  };
  return points;
}

void Player::rotate(float deg, Vector2D origin) { return; }
void Player::scale(float sx, float sy, Vector2D origin) { return; }
void Player::draw(Renderer *rp) { currentSprite->draw(rp); }
