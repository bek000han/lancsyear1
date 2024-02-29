package Java_coursework.GameArena;

import java.util.ArrayList;
import java.util.List;

public class Sample
{
    
    public static void main(String[] args)
    {
        GameArena arena = new GameArena(500, 300);
        Ball b = new Ball(50, 150, 20, "BLACK");
        Rectangle r1 = new Rectangle(0, 0, 500, 10, "BLUE");
        Rectangle r2 = new Rectangle(0, 290, 500, 10, "BLUE");
        Text t = new Text("FIGHT TO THE DEATH", 10, 200, 50, "RED");

        List projectiles = new ArrayList<Rectangle>();
        arena.addBall(b);
        arena.addRectangle(r1);
        arena.addRectangle(r2);
        arena.addText(t);
        arena.addKeyListener(arena);
        arena.setBackgroundImage("/home/maulen/h-drive/coursefiles/year1/lancsyear1-1/scc111/GameArena/background.png");
        
        while(true)
        {
            arena.pause();
            if (arena.keyPressed();)
        }
    }

}