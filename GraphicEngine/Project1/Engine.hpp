#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <vector>
#include "BitmapHandler.hpp"
#include "DrawableObject.hpp"
#include "Initializer.hpp"
#include "PrimitiveRenderer.hpp"
#include "InputState.hpp"
#include "Renderer.hpp"
#include "ObjectManager.hpp"
#include "UpdatableObject.hpp"

class Engine : public Renderer, public Initializer, public ObjectManager
{
public:
    Engine();
    ~Engine();

    bool init();
    void setGraphicsMode(bool fullscreen, sf::VideoMode videoMode);
    void setParameters(int frameRate, bool enableKeyboard, bool enableMouse);
    void run();
    PrimitiveRenderer *getPrimitiveRenderer() override;
    sf::RenderTarget *getRenderTarget() override;
    void beginPrimitiveBatch() override;
    void endPrimitiveBatch() override;
    void addObject(GameObject* obj) override;
    void removeObject(GameObject* obj) override;
    BitmapHandler* getBitmapHandler() override;
private:
    InputState getInputState();
    bool loadAssets();
    bool initializeObjects();
    void handleEvents(); 
    void update();
    void render();
    void draw();
    void clearScreen(const sf::Color& color);
    void logError(const std::string& message);
    void cleanup();
    InputState inputState;
    std::vector<GameObject *> objects;
    std::vector<DrawableObject *> drawables;
    std::vector<UpdatableObject *> updatables;

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
};

#endif
