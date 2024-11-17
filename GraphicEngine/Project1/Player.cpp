#include "Player.hpp"
Player::Player(Vector2D pos) : position(pos.x, pos.y) {}
Player::~Player() {
  delete leftSprite;
  delete rightSprite;
  delete upSprite;
  delete downSprite;
}

void Player::update(const InputState &input, ObjectManager *manager) {
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
  translate(inputV);
}

bool Player::init(Initializer *initializer) {
  auto handler = initializer->getBitmapHandler();
  leftSprite = new BitmapObject(position, *handler->getTexture("player_left"));
  rightSprite =
      new BitmapObject(position, *handler->getTexture("player_right"));
  upSprite = new BitmapObject(position, *handler->getTexture("player_up"));
  downSprite = new BitmapObject(position, *handler->getTexture("player_down"));
  currentSprite = downSprite;
  return true;
}

void Player::translate(Vector2D vec) {
  position.x += vec.x;
  position.y += vec.y;
  leftSprite->translate(vec);
  rightSprite->translate(vec);
  upSprite->translate(vec);
  downSprite->translate(vec);
}

void Player::rotate(float deg, Vector2D origin) { return; }
void Player::scale(float sx, float sy, Vector2D origin) { return; }
void Player::draw(Renderer *rp) { currentSprite->draw(rp); }
