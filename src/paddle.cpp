#include "paddle.h"

Paddle::Paddle(int width, int height, bool left){
    paddleHeight = 100.0f;
    paddleWidth = 10.0f;
    this->left = left;
    rect.setSize(sf::Vector2f(paddleWidth, paddleHeight));
    rect.setOrigin({paddleWidth / 2, paddleHeight / 2});
    if(left){
        rect.setPosition(sf::Vector2f(50.0f, float(height / 2)));
    }else{
        rect.setPosition(sf::Vector2f(float(width - 50), float(height / 2)));
    }
}

sf::RectangleShape& Paddle::getPaddle(){
    return rect;
}

float Paddle::getHeight(){
    return paddleHeight;
}

float Paddle::getWidth(){
    return paddleWidth;
}

sf::Vector2f Paddle::getPosition(){
    return rect.getPosition();
}

void Paddle::getInput(){
    sf::Vector2f paddlePos = rect.getPosition();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && left){
        if(paddlePos.y >= 50.0f){
            rect.move({0.0f, -3.0f});
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && left){
        if(paddlePos.y <= 720 - 50.0f){
            rect.move({0.0f, 3.0f});
        }
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !left){
        if(paddlePos.y >= 50.0f){
            rect.move({0.0f, -3.0f});
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !left){
        if(paddlePos.y <= 720 - 50.0f){
            rect.move({0.0f, 3.0f});
        }
    }
    
}