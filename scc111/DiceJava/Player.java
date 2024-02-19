package scc111.DiceJava;
import java.util.Scanner;

public class Player {
    private String name;
    private Scanner scan;
    
    public Player(String name){
        this.name = name;
        this.scan = new Scanner(System.in);
    }

    public int makeGuess(){
        System.out.println(name + ", make a guess (between 1 and 6): ");
        int guess = scan.nextInt();
        return guess;
    }

}
