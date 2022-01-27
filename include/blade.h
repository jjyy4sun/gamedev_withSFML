#ifndef BLADE_H_
#include <SFML/Graphics.hpp>

class Blade
{
private:
    /* data */
    void processEvents();
    void update();
    void render();
public:
    Blade(/* args */);
    ~Blade();
    void run();
private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
};


#endif // BLADE_H_