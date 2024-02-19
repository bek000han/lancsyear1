package scc111.DiceJava;


public class Driver {
    public static void main(String[] args) {
        testGame("Player 1", 6);
        testGame("Player 2", 4);
    }

    private static void testGame(String playerName, int numSides) {
        Dice sixSidedDice = new Dice(6);

        Player player = new Player("Player 1");

        int guess = player.makeGuess();
        int rollResult = sixSidedDice.roll();

        displayResult(playerName, guess, rollResult);
    }

    private static void displayResult(String playerName, int guess, int rollResult) {
        if (guess == rollResult) {
            System.out.printf("Congratulations, %s! %d is correct. You win!\n", playerName, guess);
        } else {
            System.out.printf("Sorry, %s. %d is incorrect. The correct answer is %d. Try again!\n",
                    playerName, guess, rollResult);
        }
    }
}