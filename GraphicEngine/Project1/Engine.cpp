// Engine.cpp
#include "Engine.hpp"

#include "LineSegment.hpp"
#include "Point2D.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <iostream>


PrimitiveRenderer * Engine::getPrimitiveRenderer() {
  return primitiveRenderer;
}

sf::RenderTarget * Engine::getRenderTarget() {
  return &renderTexture;
}

Engine::Engine() :
  window(nullptr),
  primitiveRenderer(nullptr),
  isFullscreen(false),
  frameRate(60),
  enableKeyboard(true),
  enableMouse(true)
{
}

Engine::~Engine()
{
  cleanup();
}

bool Engine::init()
{
  try {
    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "SFML Engine", isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    window->setFramerateLimit(frameRate);
    auto size = window->getSize();
    renderTexture.create(size.x,size.y);
    primitiveRenderer = new PrimitiveRenderer();
    std::cout << "SFML loaded succesfully.\n";
    return true;
  }
  catch (const std::exception& e) {
    logError("Problem with inicializing: " + std::string(e.what()));
    return false;
  }
}

void Engine::setGraphicsMode(bool fullscreen, sf::VideoMode videoMode)
{
  isFullscreen = fullscreen;
  if (window) {
    delete window;
    window = new sf::RenderWindow(videoMode, "SFML Engine", isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    auto size = window->getSize();
    renderTexture.create(size.x,size.y);
  }
}

void Engine::setParameters(int frameRate, bool enableKeyboard, bool enableMouse)
{
  this->frameRate = frameRate;
  this->enableKeyboard = enableKeyboard;
  this->enableMouse = enableMouse;
  if (window) {
    window->setFramerateLimit(frameRate);
  }
}


bool Engine::loadAssets() {
  bitmapHandler.loadFromFile("player", "./assets/player_up.png");
  return true;
}


bool Engine::initializeObjects() {
  player = new Player({200.0, 200.0}, &bitmapHandler);
  return true;
}

void Engine::run()
{
  if (!loadAssets()) {
    logError("Assets not loaded");
  }
  if (!initializeObjects()) {
    logError("Error with initialization.");
  }


  if (!window) {
    logError("Window not inicialized.");
    return;
  }

  while (window->isOpen())
  {
    handleEvents();
    update();
    render();
  }
}

void Engine::handleEvents()
{
  sf::Event event;
  while (window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window->close();

    if (enableKeyboard) {
      if (event.type == sf::Event::KeyPressed) {
        inputState.setKeyDown(event.key.code);
        if (event.key.code == sf::Keyboard::Escape) {
          window->close();
        }
      }
      if (event.type == sf::Event::KeyReleased) {
        inputState.setKeyUp(event.key.code);
      }
    }

    if (enableMouse && event.type == sf::Event::MouseButtonPressed) {
      pressedX = event.mouseButton.x; 
      pressedY = event.mouseButton.y;
    }
  }
}

void Engine::update()
{
  sf::Time elapsed = clock.getElapsedTime();
  player->update(inputState);
}



void Engine::beginPrimitiveBatch() {
  renderTexture.display();
  screenBuffer = renderTexture.getTexture().copyToImage();
  primitiveRenderer->setImage(&screenBuffer);
}
void Engine::endPrimitiveBatch() {
  sf::Texture updatedTexture;
  updatedTexture.loadFromImage(screenBuffer);
  sf::Sprite updatedSprite(updatedTexture);
  renderTexture.draw(updatedSprite);
}
void Engine::draw() {
  beginPrimitiveBatch();
  LineSegment myLine({80, 80}, {200, 200}, sf::Color::Red);
  myLine.rotate(clock.getElapsedTime().asSeconds()*360,myLine.getCenterPoint());
  myLine.draw(primitiveRenderer);
  Point2D marker(myLine.getCenterPoint(), sf::Color::Green);
  marker.draw(primitiveRenderer);
  primitiveRenderer->drawRect(80, 80, 20, 20, sf::Color::Blue, sf::Color::Cyan);
  primitiveRenderer->drawCircle(400, 400, 20, sf::Color::Green, sf::Color::White);
  endPrimitiveBatch();

  player->draw(this);
}

void Engine::render()
{
  renderTexture.clear();
  draw();
  renderTexture.display();
  sf::Sprite windowSprite(renderTexture.getTexture());
  window->clear();
  window->draw(windowSprite);
  window->display();
}

void Engine::clearScreen(const sf::Color& color)
{
  if (window) {
    window->clear(color);
  }
}

void Engine::logError(const std::string& message)
{
  std::cerr << "Error: " << message << "\n";
}

void Engine::cleanup()
{
  if (primitiveRenderer) {
    delete primitiveRenderer;
    primitiveRenderer = nullptr;
  }
  if (window) {
    delete window;
    window = nullptr;
    std::cout << "Window closed.\n";
  }
}
