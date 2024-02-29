package Java_coursework.DiceJava;

public class Dice {
    private int numsides;

    public Dice(int numSides){
        this.numsides = numSides;
    }
    
    public int roll(){
        return (int)(Math.random() * numsides) + 1;
    }
}
