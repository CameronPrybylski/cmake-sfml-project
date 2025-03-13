#include <SFML/Graphics.hpp>

#ifndef _BALL_H_
#define _BALL_H_

#include "paddle.h"

class Ball{
private:
    sf::CircleShape entity;
    float xVelocity;
    float yVelocity;
public:
    Ball();
    sf::CircleShape& getBall();
    void reset();
    sf::Vector2f getBallPosition();
    float updatePos();
    void checkCollision(sf::Vector2f position, float height, float width, float paddleEdge);
};
#endif