#pragma once

#include<memory>

#include "cat.h"

class Handler {
public:
    Handler() : catSprite{std::make_unique<Cat>()} {}
    void run(sf::RenderWindow &window);

private:
    std::unique_ptr<Cat> catSprite;

    sf::Vector2f setCatPosition();
    void makeCatJump(sf::RenderWindow &window);
};