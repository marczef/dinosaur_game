#include <iostream>
#include <chrono>

#include "cat.h"

namespace {
    sf::Texture loadTexture() {
        sf::Texture texture;
        bool loaded = texture.loadFromFile("img/cat.png");
        std::cout << "loaded : " << loaded <<std::endl;
        return texture;
    }
}

Cat::Cat() : texture(loadTexture()), catSprite(texture) {
    catSprite.setPosition(sf::Vector2f({125, 350}));
    clock.restart();
}

void Cat::tryCatJump() {
    if(clock.getElapsedTime() >= std::chrono::seconds(1)) {
        isJumping = false;
    }

    if(!isJumping){
        catSprite.move(sf::Vector2f({10, -10}));
        clock.restart();
        isJumping = true;
    }
}
