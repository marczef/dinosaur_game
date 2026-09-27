#include <iostream>
#include <chrono>
#include <cmath>

#include "cat.h"

namespace {
    constexpr std::chrono::seconds JUMP_TIME{500};
    constexpr sf::Vector2f NORMAL_POS{125, 350};

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

void Cat::toggleCatJump() {
    if(clock.getElapsedTime() >= std::chrono::seconds(1)) {
        isJumping = false;
    }

    if(!isJumping){
        clock.restart();
        isJumping = true;
    }
}

sf::Vector2f Cat::getPosition() {

    if(!isJumping || clock.getElapsedTime() >= std::chrono::seconds(1)) {
        isJumping = false;
        catSprite.setPosition(NORMAL_POS);
        return NORMAL_POS;
    }
    else {
        sf::Vector2f pos{125, 350};
        float h = -500 * (std::pow(clock.getElapsedTime().asSeconds(), 2)) + 500 * clock.getElapsedTime().asSeconds();
        std::cout << "h : " << h << std::endl;

        pos.y -= h;

        catSprite.setPosition(pos);

        return pos;
    }
}