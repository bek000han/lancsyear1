#include "MicroBit.h"

MicroBit uBit;

// Function to compute the Fibonacci sequence up to n terms
void computeFibonacci(int n) {
    int *fibs;

    fibs = (int *)malloc(n*sizeof(int));

    uBit.serial.printf("Fibonacci Sequence (First %d terms):\r\n", n);

    for (int i = 0; i < n; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
        uBit.sleep(500); // Delay for readability (500ms)
    }

    uBit.serial.printf("result is %d\r\n", fibs[n]);
    free(fibs);
}

int main() {
    uBit.init();

    uBit.serial.printf("Micro:Bit Fibonacci Sequence Calculator\r\n");

    while (1) {
        // print prompt for input number
        uBit.serial.printf("Enter the number of terms (0 to exit): ");
        int n = 0;

        // read user input until a newline is sent and store string in 
        // variable ret. 
        ManagedString ret = uBit.serial.readUntil("\r\n"); 
        for (int i = 0; i < ret.length(); i++) {
            n = n*10 + ret.charAt(i) - '0';
        }
        // By default the serial input will not appear on the screen, 
        // so we need to print it explicitly
        uBit.serial.printf("%d\r\n", n);

        if (n == 0) {
            continue; // Exit the program if the user enters 0
        }

        computeFibonacci(n);
    }

    uBit.serial.printf("Goodbye!\r\n");
    release_fiber(); // Release the main fiber to stop the program

    return 0;
}