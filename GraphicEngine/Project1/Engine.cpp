// Engine.cpp
#include "Engine.hpp"

Engine::Engine() :
    window(nullptr),
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
        std::cout << "SMFL loaded succesfully.\n";
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
    clearScreen(sf::Color::Black);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    window->draw(shape);

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
    if (window) {
        delete window;
        window = nullptr;
        std::cout << "Window closed.\n";
    }
}
