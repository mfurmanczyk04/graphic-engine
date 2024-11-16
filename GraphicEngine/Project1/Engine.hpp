#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "BitmapHandler.hpp"
#include "PrimitiveRenderer.hpp"
#include "InputState.hpp"
#include "Renderer.hpp"
#include "Player.hpp"

class Engine : public Renderer
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
    PrimitiveRenderer *getPrimitiveRenderer() override;
    sf::RenderTarget *getRenderTarget() override;
    InputState getInputState();
private:
    // Metody prywatne
    bool loadAssets();
    bool initializeObjects();
    void handleEvents(); 
    void update(); // Aktualizacja logiki gry
    void render();
    void draw();
    void beginPrimitiveBatch();
    void endPrimitiveBatch();
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
    
    BitmapHandler bitmapHandler;


    // temporary 
    Player *player;


};

#endif
