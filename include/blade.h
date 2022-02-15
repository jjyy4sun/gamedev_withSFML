#ifndef BLADE_H_
#define BLADE_H_
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "define.h"
#include "Aircraft.hpp"

class Blade
{
private:
    /* data */
    void processEvents();
    void update(sf::Time time);
    void render();
    void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);
public:
    Blade(/* args */);
    ~Blade();
    void run();
private:
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    ResourceHolder<sf::Texture, Textures::ID> mTextureHolder;
    Aircraft *aircraft{nullptr};

    bool isUpPressed{false};
    bool isDownPressed{false};
    bool isLeftPressed{false};
    bool isRightPressed{false};
};


#endif // BLADE_H_