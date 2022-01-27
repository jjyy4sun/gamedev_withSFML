#include<iostream>
#include <SFML/Graphics.hpp>

#include "blade.h"

int tellusIfworks() {
    std::cout << "it works!"<<std::endl;
    return 0;
}

void Blade::run() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    sf::CircleShape shape;
    shape.setRadius(40.0f);
    shape.setPosition(sf::Vector2<float>(100.0f, 100.0f));
    shape.setFillColor(sf::Color::Cyan);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
}