#ifndef CIRCLE_H
#define CIRCLE_H 

#include <string>

class Circle {

    public:

        // Constructor: Creates a new Circle, with the given geometry.
        Circle(int xPosition, int yPosition, int size, std::string col);

        // Returns the current X coordinate of this circle.
        int getX();

        // Returns the current Y coordinate of this circle.
        int getY();

        // Returns the current radius of this circle.
        int getRadius();

        // Returns the current colour of this circle.
        std::string getColour();

        // Returns the current colour of this circle.
        void setColour(std::string);

        // Returns the current X coordinate of this circle.
        void setX(int x);

        // Returns the current Y coordinate of this circle.
        void setY(int y);

        // Returns the current radius of this circle.
        void setRadius(int radius);

        // Move the position of this circle relative to it current position
        void move(int dx, int dy);

    private:
        int x;
        int y;
        int radius;
        std::string colour;
};

#endif
