#pragma once

#include<memory>

#include "cat.h"

class Handler {
public:
    Handler() : catSprite{std::make_unique<Cat>()} {}
    void run(sf::RenderWindow &window);

private:
    std::unique_ptr<Cat> catSprite;

    void makeCatJump(sf::RenderWindow &window);
};