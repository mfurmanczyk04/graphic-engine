// main.cpp
#include "Engine.hpp"

int main()
{
    Engine engine;

    if (engine.init()) {
        engine.setGraphicsMode(true, sf::VideoMode(2160, 1440));
        engine.setParameters(60, true, true);
        engine.run();
    }

    return 0;
}
