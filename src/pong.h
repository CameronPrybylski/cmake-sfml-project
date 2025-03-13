#ifndef _PONG_H_
#define _PONG_H_

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"
#include "net.h"

class Pong{

private:
    Ball ball;
    Paddle left;
    Paddle right;
    Net net;
    sf::RenderWindow window;
    int screenWidth;
    int screenHeight;
    int leftScore;
    int rightScore;
    sf::Text lefttext;
    sf::Text righttext;
    sf::Font font;

public:
    Pong(int screenWidth, int screenHeight);
    void playGame();

};

#endif