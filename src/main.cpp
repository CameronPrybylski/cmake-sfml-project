#include <SFML/Graphics.hpp>
#include "ball.h"
#include "net.h"
#include "paddle.h"
#include "pong.h"

int main()
{
    //auto window = sf::RenderWindow(sf::VideoMode({1280, 720}), "CMake SFML Project");
    //window.setFramerateLimit(144);

    Pong game(1280, 720);
/*
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        */
       game.playGame();
    //}
}
