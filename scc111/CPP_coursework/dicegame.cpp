#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Dice{
    int numSides = 6;

    public:
        int roll();
};

int Dice::roll(){
    srand(time(NULL));
    return rand() % numSides + 1;
}

class Player{
    int playerID;
    int score = 0;

    public:
        void setPlayerID(int id);
        void makeGuess(Dice dice);
        void updateScore(int points);
        void displayScore();
};

void Player::setPlayerID(int id){
    playerID = id;
}

void Player::updateScore(int points){
    score += points;
}

void Player::displayScore(){
    std::cout << "Player" << playerID << "'s score is " << score << "\n";
}

void Player::makeGuess(Dice dice){
    int roll = dice.roll();
    int guess;

    std::cout << "Player" << playerID << " > Enter your guess: \n";
    std::cin >> guess;

    if (roll == guess){
        std::cout << "Your guess is correct!\n";
        updateScore(1);
    } else {
        std::cout << "Your guess is wrong.\n";
    }
    return;
}

void Game(Player players[], Dice dice, int numberOfRounds, int numberOfPlayers);

int main(){
    Dice dice;
    Player player1, player2, player3;
    player1.setPlayerID(1);
    player2.setPlayerID(2);
    player3.setPlayerID(3);

    Player players[] = {player1, player2, player3};
    Game(players, dice, 3, 3);
    return 0;
}

void Game(Player players[], Dice dice, int numberOfRounds, int numberOfPlayers){
    for (int i = 0; i < numberOfRounds; i++){
        for (int j = 0; j < numberOfPlayers; j++){
            players[j].makeGuess(dice);
        }
        std::cout << "\n";
        for (int k = 0; k < numberOfPlayers; k++){
            players[k].displayScore();
        }
        std::cout << "\n";
    }
}