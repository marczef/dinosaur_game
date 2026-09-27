#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Cat {
private:
    sf::Texture texture;

public:
    Cat();

    sf::Sprite catSprite;

    void toggleCatJump();
    sf::Vector2f getPosition();

private:
    sf::Clock clock;
    bool isJumping{false};
};