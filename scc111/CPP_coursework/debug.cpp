#include <stdio.h>
#include <ctime>
#include <math.h>

#define DEBUG 1

class Dice {
    private:
    int numSides,guess; 
    
    public:
    Dice(int sides);
    void roll();
    Dice(){};
    int getNumSides();
    int getGuess();
    void setGuess(int num);
};

int Dice::getNumSides(){
    return numSides;
}

int Dice::getGuess(){
    return guess;
}

void Dice::setGuess(int num){
    guess = num;
}


Dice::Dice(int sides){
    if(sides >= 2)
        numSides = sides;
    else
        printf("You can't create a Dice with less than two sides. A default value of 6 is chosen.");
        numSides = 6;
}
void printResult(Dice d, int rolled_number){
    if (d.getGuess()-rolled_number==0)
        printf("Better luck next time! the dice rolled %d\n", rolled_number);
    else
        printf("Lucky you! You WON..\n");
}

int roll(int numSides) {
    int rollResult = rand() % numSides + 1;
    numSides = rollResult;
    
    return rollResult;
}

void makeAGuess(Dice d){
    int guess;
    printf("Make a guess from 1 to %d.\n",d.getNumSides());
    scanf("%d", &guess);
    d.setGuess(guess);
}

int main() {
    srand(time(NULL));

    int numSides;
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);
    Dice sixSidedDice(numSides);

    int rolled_number = roll(numSides);

    makeAGuess(sixSidedDice);

    printResult(sixSidedDice,numSides);


    return 0;
}