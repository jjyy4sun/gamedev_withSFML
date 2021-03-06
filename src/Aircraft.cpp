#include"Aircraft.hpp"

Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Eagle:
          return Textures::Eagle;
        case Aircraft::Raptor:
          return Textures::Raptor;
    }
}

Aircraft::Aircraft(Type type, const TextureHolder& textures) : mType(type),
                                                                mSprite(textures.get(toTextureID(type))) {
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width/2.f, bounds.height/2.f);
}