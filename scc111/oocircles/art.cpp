#include <iostream>
#include "Canvas.h"
#include "Circle.h"

int main(){
    Canvas canvas(800, 600); // This create an 800x600 canvas 

    Circle circle1(100, 100, 30, "white"); // a new white circle with a 30 radius in position (100,100)

    canvas.addCircle(circle1); 

    canvas.update();

    while(1)
    {
        circle1.move(1,0);
        canvas.update();
        canvas.pause();
    }
    
    std::cout << "Canvas Updated!" << std::endl;
    return 0;
}