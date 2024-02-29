#ifndef CANVAS_H
#define CANVAS_H

#include "Circle.h"
#include <vector>
  
class Canvas {
    public:
        // Create a representation of a canvas of the given size. 
        Canvas(int width, int height);

        // Returns the width of the canvas
        int getWidth();
        
        // Returns the height of the canvas
        int getHeight();
        
        // Add a circle to this canvas
        void addCircle(Circle& circle);

        // Update the JSON file with all the graphical objects on this canvas
        void update();

        // Clear the canvas of any added circles
        void clear();

        // Pause for one frame (approx 1/50th of a second)
        void pause();
        
    private:
        int canvasWidth;
        int canvasHeight;
        std::vector<Circle *> circles;
};

#endif
