#include <iostream>

#include "handler.h"

void Handler::run(sf::RenderWindow &window) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        catSprite->toggleCatJump();
        
    }
    setCatPosition();

    window.draw(catSprite->catSprite);
    
}

sf::Vector2f Handler::setCatPosition() {
    return catSprite->getPosition();
}