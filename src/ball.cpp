#include "ball.h"
#include<cmath>

Ball::Ball(){
    entity.setRadius(5.0f);
    entity.setOrigin({entity.getRadius(), entity.getRadius()});
    entity.setPosition({640.0f, 360.0f});
    entity.setFillColor(sf::Color::Red); 
    xVelocity = 3.0;
    yVelocity = 3.0;
}

sf::CircleShape& Ball::getBall(){
    return entity;
}

void Ball::reset(){
    entity.setPosition({640.0f, 360.0f});
    xVelocity = 3.0;
    yVelocity = 3.0;
}

sf::Vector2f Ball::getBallPosition(){
    return entity.getPosition();
}

float Ball::updatePos(){
    sf::Vector2f circlePosition = getBallPosition();
    if(circlePosition.y < 0 || circlePosition.y > 720 - entity.getRadius()){
        yVelocity *= -1;
    }
    if(circlePosition.x < 0 || circlePosition.x > 1280 - entity.getRadius()){
        //xVelocity *= -1;
        reset();
        if(circlePosition.x < 0){
            return 0;
        }
        return 1280;
    }
    circlePosition.x += xVelocity;
    circlePosition.y += yVelocity;
    entity.setPosition(circlePosition);
    return 100.0;
}

void Ball::checkCollision(sf::Vector2f position, float height, float width, float paddleEdge){
    float ballDiameter = entity.getRadius() * 2;
    sf::Vector2f ballPosition = getBallPosition();
    for(float i = 0; i < height / 2; i++){
        float distanceBetweenTop = sqrt(abs(ballPosition.x - position.x + paddleEdge) + abs(ballPosition.y - position.y - i));
        float distanceBetweenBottom = sqrt(abs(ballPosition.x - position.x + paddleEdge) + abs(ballPosition.y - position.y + i));
        if(distanceBetweenTop <= entity.getRadius() || distanceBetweenBottom <= entity.getRadius()){
            xVelocity *= -1;
        }
    }
    //float distanceBetween = sqrt(abs(ballPosition.x - position.x) + abs(ballPosition.y - position.y));
}