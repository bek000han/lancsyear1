// source/main.cpp
#include "MicroBit.h"

MicroBit uBit; // The MicroBit object

// --- DECLARE GLOBAL VARIABLES, STRUCTURE(S) AND ADDITIONAL FUNCTIONS (if needed) HERE ---
int val[2] = {1};

// This links your Assembly function with the CoDAL runtime.
extern "C"
{
    int eth_mult(int val1, int val2);
}

// Event handler for buttons A and B pressed together
void onButtonAB(MicroBitEvent e)
{
    // DEVELOP CODE HERE
    int res = eth_mult(val[0], val[1]);
    uBit.display.scroll(res);
}

// Event handler for button A
void onButtonA(MicroBitEvent e)
{
    // DEVELOP CODE HERE
    int a = microbit_random(98) + 1;
    uBit.display.scroll(a);
    val[0] = a;
}

// Event handler for button B
void onButtonB(MicroBitEvent e)
{
    // DEVELOP CODE HERE
    int b = microbit_random(98) + 1;
    uBit.display.scroll(b);
    val[1] = b;
}

int main()
{
    // Initialise the micro:bit
    uBit.init();
    // initialize the random number generator
    uBit.seedRandom();

   // Ensure that different levels of brightness can be displayed
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

    // Set up listeners for button A, B and the combination A and B.
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, onButtonAB);

    // You probably do not need to do anything after this point in the main method.

    // Enter the scheduler indefinitely and, if there are no other processes running,
    // let the processor go to a power efficient sleep WITHOUT ceasing execution.
    release_fiber();
}