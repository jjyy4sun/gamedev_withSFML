#ifndef DEFINE_H_
#define DEFINE_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define RESOURCE_DIR "../resource"
#elif __APPLE__
#define RESOURCE_DIR "resource"
#elif __LINUX__
#define RESOURCE_DIR "resource"
#endif

#define PLAYER_SPEED 1.0f
const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

namespace Textures {
    enum ID {
        Airplane,
        Missile,
        Lanscape
    };
}

#endif DEFINE_H_