#include <iostream>

#include "handler.h"

void Handler::run(sf::RenderWindow &window) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        catSprite->tryCatJump();
        
    }

    // sf::RectangleShape test(sf::Vector2f(50, 50));
    // test.setFillColor(sf::Color::Green);
    // test.setPosition(sf::Vector2f({125, 350}));
    // window.draw(test);

    window.draw(catSprite->catSprite);
    
}