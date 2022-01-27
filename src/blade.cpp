#include<iostream>
#include <SFML/Graphics.hpp>
#include "blade.h"

Blade::Blade() : mWindow(sf::VideoMode(640, 480), "SFML Application"),
                mPlayer() {
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(sf::Vector2<float>(100.0f, 100.0f));
    mPlayer.setFillColor(sf::Color::Cyan);
}

void Blade::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}

void Blade::update() {

}

void Blade::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Blade::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}


Blade::~Blade() {
    
}