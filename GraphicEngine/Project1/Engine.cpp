// Engine.cpp
#include "Engine.hpp"

#include "Color.hpp"
#include "Point2D.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <iostream>

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
        primitiveRenderer = new PrimitiveRenderer(&renderTexture);
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
        delete primitiveRenderer;
        window = new sf::RenderWindow(videoMode, "SFML Engine", isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
        auto size = window->getSize();
        renderTexture.create(size.x,size.y);
        primitiveRenderer = new PrimitiveRenderer(&renderTexture);
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

void Engine::run()
{
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

        if (enableKeyboard && event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
        }

        if (enableMouse && event.type == sf::Event::MouseButtonPressed) {
            std::cout << "(x,y): " << event.mouseButton.x << ", " << event.mouseButton.y << "\n";
        }
    }
}

void Engine::update()
{
    sf::Time elapsed = clock.restart();
}

void Engine::render()
{
    primitiveRenderer->setColor(Color::Black);
    primitiveRenderer->clearScreen();
    primitiveRenderer->setColor(Color::Magenta);

    primitiveRenderer->drawCircle(200.0f, 200.0f, 30.0f);
    //primitiveRenderer->boundryFill(200, 200, Color::Magenta, Color::Black);

    //primitiveRenderer->drawLineBuiltin(800.0f, 600.0f, 700.0f, 500.0f);
    primitiveRenderer->drawLine(800.0f, 600.0f, 700.0f, 500.0f);

    Vector2D pointPos(80.0f, 80.0f);
    Point2D point(pointPos);
    point.draw(primitiveRenderer);


    renderTexture.display();
    windowSprite.setTexture(renderTexture.getTexture());
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
