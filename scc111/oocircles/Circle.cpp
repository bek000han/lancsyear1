#include "Circle.h"

// Constructor: Creates a new Circle, with the given geometry.
Circle::Circle(int xPosition, int yPosition, int size, std::string col)
{
    x = xPosition;
    y = yPosition;
    radius = size;
    colour = col;
}

// Returns the current X coordinate of this circle.
int Circle::getX(){
    return x;
}

// Returns the current Y coordinate of this circle.
int Circle::getY(){
    return y;
}          

// Returns the current radius of this circle.
int Circle::getRadius(){
    return radius;
}

// Returns the current color of this circle.
std::string Circle::getColour(){
    return colour;
}

// Returns the current colour of this circle.
void Circle::setColour(std::string col){
    colour = col;
}

// Returns the current X coordinate of this circle.
void Circle::setX(int xPosition){
    x = xPosition;
}

// Returns the current Y coordinate of this circle.
void Circle::setY(int yPosition){
    y = yPosition;
}

// Returns the current radius of this circle.
void Circle::setRadius(int size){
    radius = size;
}

// Move the position of this circle relative to it current position
void Circle::move(int dx, int dy)
{
    x = x + dx;
    y = y + dy;
}

