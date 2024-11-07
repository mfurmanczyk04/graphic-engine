#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "PrimitiveRenderer.hpp"
#include "InputState.hpp"

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
    PrimitiveRenderer *getPrimitiveRenderer();
    InputState getInputState();
private:
    // Metody prywatne
    void handleEvents(); 
    void update(); // Aktualizacja logiki gry
    void render();
    void _renderBegin();
    void _renderEnd();
    void clearScreen(const sf::Color& color);
    void logError(const std::string& message);
    void cleanup();

    InputState inputState;


    sf::RenderWindow* window;
    sf::RenderTexture renderTexture;
    bool isFullscreen;
    int frameRate;
    bool enableKeyboard;
    bool enableMouse;
    sf::Clock clock;
    PrimitiveRenderer *primitiveRenderer; 
    float pressedX;
    float pressedY;
    sf::Image screenBuffer;
    float rotation = 0;
};

#endif
