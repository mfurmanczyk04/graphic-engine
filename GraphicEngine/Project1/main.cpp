// main.cpp
#include "Engine.hpp"

int main()
{
    Engine engine;

    if (engine.init()) {
        engine.setGraphicsMode(false, sf::VideoMode(1280, 720));
        engine.setParameters(60, true, true);
        engine.run();
    }

    return 0;
}
