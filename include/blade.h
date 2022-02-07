#ifndef BLADE_H_
#include <SFML/Graphics.hpp>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define RESOURCE_DIR "../resource"
#elif __APPLE__
#define RESOURCE_DIR "resource"
#elif __LINUX__
#define RESOURCE_DIR "resource"
#endif

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