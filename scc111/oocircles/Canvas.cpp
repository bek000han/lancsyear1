#include "Canvas.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

// Create a representation of a canvas of the given size. 
Canvas::Canvas(int width, int height){
    canvasHeight = width;
    canvasHeight = height;
}

// Add a circle to this canvas
void Canvas::addCircle(Circle& circle) {
    circles.push_back(&circle);
}

// Update the JSON file with all the graphical objects on this canvas
void Canvas::update() {
    std::ofstream outFile("circles.json");

    if (outFile.is_open()) {
    
        outFile << "[";
        for (Circle *circle : circles) {
            outFile << "{ \"shape\": \"circle\", \"parameters\": { \"x\": "<< circle->getX() << ", \"y\": " << circle->getY() << ", \"radius\": " << circle->getRadius() << ", \"color\": \"" << circle->getColour() << "\" } },";
        }
        if (!circles.empty()) {
            outFile.seekp(-1, std::ios_base::end); // Remove the last comma
        }
        outFile << "]";
        outFile.close();
    } else {
        std::cerr << "Error opening circles.json file" << std::endl;
    }
}

// Clear the canvas of any added circles
void Canvas::clear()
{
    circles.clear();
}

int Canvas::getWidth() {
    return canvasWidth;
}

int Canvas::getHeight() {
    return canvasHeight;
}

// Pause for one frame (approx 1/50th of a second)
void  Canvas::pause()
{
    usleep(20000);
}

