#ifndef _PADDLE_H_
#define _PADDLE_H_

#include<SFML/Graphics.hpp>

class Paddle{

private:
    sf::RectangleShape rect;
    float paddleHeight;
    float paddleWidth;
    bool left;

public:
    Paddle(int width, int height, bool left);
    sf::RectangleShape& getPaddle();
    void getInput();
    float getHeight();
    float getWidth();
    sf::Vector2f getPosition();


};

#endif