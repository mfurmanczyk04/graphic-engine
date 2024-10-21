// Engine.hpp
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Engine
{
public:
    // Konstruktor i destruktor
    Engine();
    ~Engine();

    // Metody publiczne
    bool init(); // Inicjalizacja biblioteki graficznej
    void setGraphicsMode(bool fullscreen, sf::VideoMode videoMode);
    void setParameters(int frameRate, bool enableKeyboard, bool enableMouse);
    void run(); // G³ówna pêtla gry

private:
    // Metody prywatne
    void handleEvents(); // Obs³uga zdarzeñ
    void update(); // Aktualizacja logiki gry
    void render();
    void clearScreen(const sf::Color& color);
    void logError(const std::string& message);

    void cleanup();

    sf::RenderWindow* window;
    bool isFullscreen;
    int frameRate;
    bool enableKeyboard;
    bool enableMouse;
    sf::Clock clock;
};

#endif
