#include<iostream>
#include <SFML/Graphics.hpp>
#include "blade.h"

const std::string eagle_path = std::string(RESOURCE_DIR).append("/Textures/eagle.png");

Blade::Blade() : mWindow(sf::VideoMode(640, 480), "SFML Application"),
                mPlayer() {
    mTextureHolder.Load(Textures::Airplane, eagle_path);
    mPlayer.setTexture(mTextureHolder.get(Textures::Airplane));
    mPlayer.setPosition(sf::Vector2<float>(100.0f, 100.0f));
}

void Blade::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type)
        {
        case sf::Event::KeyPressed: {
            handleKeyboardInput(event.key.code, true); 
            break;
        }
        case sf::Event::KeyReleased: {
            handleKeyboardInput(event.key.code, false); 
            break;
        }
        case sf::Event::Closed: {
            mWindow.close();
            break;
        }
        default:
            break;
        }
    }
}

void Blade::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);

    if (isUpPressed) {
        movement.y -= PLAYER_SPEED;
        isUpPressed = false;
    }
    if (isDownPressed) {
        movement.y += PLAYER_SPEED;
        isDownPressed = false;
    }
    if (isLeftPressed) {
        movement.x -= PLAYER_SPEED;
        isLeftPressed = false;
    }
    if (isRightPressed) {
        movement.x += PLAYER_SPEED;
        isRightPressed = false;
    }
    // mPlayer.move(movement);
    mPlayer.move(movement * deltaTime.asSeconds());
}

void Blade::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Blade::run() {
    sf::Clock clock;
    sf::Time timeSpendFromLastFrame = sf::Time::Zero;
    while (mWindow.isOpen()) {
        timeSpendFromLastFrame += clock.restart();
        processEvents();
        if (timeSpendFromLastFrame > TimePerFrame) {
            timeSpendFromLastFrame -= TimePerFrame; 
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Blade::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
        isUpPressed = true;
    } else if (key == sf::Keyboard::S) {
        isDownPressed = true;
    } else if (key == sf::Keyboard::A) {
        isLeftPressed = true;
    } else if(key == sf::Keyboard::D) {
        isRightPressed = true;
    }
}

Blade::~Blade() {
    
}