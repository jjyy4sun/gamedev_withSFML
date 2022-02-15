#pragma once
#include"Entity.hpp"
#include"ResourceHolder.hpp"
#include "define.h"

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class Aircraft : public Entity {
  public:
    enum Type {
        Eagle,
        Raptor
    };

    explicit Aircraft(Type type, const TextureHolder& textures);

  private:
    Type mType;
    sf::Sprite mSprite;
};