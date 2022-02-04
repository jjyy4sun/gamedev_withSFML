#ifndef BLADE_H_
#include <SFML/Graphics.hpp>

#define PLAYER_SPEED 1.0f
const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

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
    sf::Texture mTexture;

    bool isUpPressed{false};
    bool isDownPressed{false};
    bool isLeftPressed{false};
    bool isRightPressed{false};
};


#endif // BLADE_H_