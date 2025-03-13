#include "net.h"

Net::Net(int width, int height){
    this->width = width;
    this->height = height;
    int numOfLines = height / 20;
    float horMid = width / 2;
    for(float i = 0; i < numOfLines; i++){
        float start = i * 20;
        float end = start + 10;
        lines.push_back({{horMid, start}});
        lines.push_back({{horMid, end}});
    }
}

std::vector<sf::Vertex>& Net::getLines(){
    return lines;
}