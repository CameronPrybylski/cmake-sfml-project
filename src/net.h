#ifndef _NET_H_
#define _NET_H_

#include<SFML/Graphics.hpp>
#include<vector>

class Net{

private:
    std::vector<sf::Vertex> lines;
    int width;
    int height;

public:
    Net(int width, int height);
    std::vector<sf::Vertex>& getLines();

};

#endif