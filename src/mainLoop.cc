#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "mainLoop.h"
#include "handler.h"

mainLoop & mainLoop::get() {
    if(main == nullptr) {
        main = std::unique_ptr<mainLoop>(new mainLoop());
    }

    return *main;
}

void mainLoop::run() {

    sf::RenderWindow appWindow(sf::VideoMode({800, 600}), "Jumping Cat Game");
    Handler handler;

    while(appWindow.isOpen())
    {
        while(const std::optional event = appWindow.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                appWindow.close();
            
        }

        appWindow.clear(sf::Color(100, 0, 0));
        handler.run(appWindow);
        appWindow.display();
    }

}
