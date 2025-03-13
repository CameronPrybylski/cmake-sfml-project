#include "pong.h"
#include <string>

Pong::Pong(int screenWidth, int screenHeight) : left(screenWidth, screenHeight, true),
    right(screenWidth, screenHeight, false),
    net(screenWidth, screenHeight), 
    lefttext(font), 
    righttext(font) {
        window = sf::RenderWindow(sf::VideoMode({(unsigned int) screenWidth,(unsigned int) screenHeight}), "CMake SFML Project");
        window.setFramerateLimit(144);
        this->screenWidth = screenWidth;
        this->screenHeight = screenHeight;
        leftScore = 0;
        rightScore = 0;
        
        if(!font.openFromFile("8bitOperatorPlus-Regular.ttf")) {
            throw std::runtime_error("Failed to load font!");
        }
        lefttext.setFont(font); // a font is required to make a text object
        // set the string to display
        lefttext.setString(std::to_string(leftScore));
        // set the character size
        lefttext.setCharacterSize(24); // in pixels, not points!
        // set the color
        lefttext.setFillColor(sf::Color::Red);
        // set the text style
        lefttext.setStyle(sf::Text::Bold | sf::Text::Underlined);

        righttext.setFont(font); // a font is required to make a text object
        // set the string to display
        righttext.setString(std::to_string(rightScore));
        // set the character size
        righttext.setCharacterSize(24); // in pixels, not points!
        // set the color
        righttext.setFillColor(sf::Color::Red);
        // set the text style
        righttext.setStyle(sf::Text::Bold | sf::Text::Underlined);

        righttext.setPosition({1260.0f, 0.0f});
}

void Pong::playGame(){
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }


        left.getInput();
        right.getInput();
        ball.checkCollision(left.getPaddle().getPosition(), 100.0f, 10.0f, 10.0f);
        ball.checkCollision(right.getPaddle().getPosition(), 100.0f, 10.0f, -10.0f);
        float point = ball.updatePos();
        if(point == 0){
            leftScore++;
        }
        else if(point == 1280){
            rightScore++;
        }
        if(leftScore >= 10 || rightScore >= 10){
            window.close();
        }
        
        //sf::CircleShape& entity = ball.getBall();
        std::vector<sf::Vertex>& lines = net.getLines();

        lefttext.setString(std::to_string(leftScore));
        righttext.setString(std::to_string(rightScore));

        window.clear();

        window.draw(ball.getBall());
        window.draw(left.getPaddle());
        window.draw(right.getPaddle());
        window.draw(&lines[0], lines.size(), sf::PrimitiveType::Lines);
        window.draw(lefttext);
        window.draw(righttext);
        window.display();
    }
}

