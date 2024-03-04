import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class TilePuzzle implements ActionListener {
    private ArrayList<TilePiece> tiles = new ArrayList<>();
    private TilePiece blankTile;
    private JFrame frame = new JFrame("Tile Puzzle Game");
    private JPanel panel = new JPanel();
    private GridLayout layout = new GridLayout(3, 4);

    public TilePuzzle() {
        createTiles();
        for (int i = 0; i < tiles.size(); i++) {
            panel.add(tiles.get(i));
        }
        frame.setContentPane(panel);
        frame.setSize(550,460);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panel.setLayout(layout);
        frame.setVisible(true);
    }

    private void createTiles(){
        int id = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 3; j++) {
                TilePiece tile = new  TilePiece("tile_"+id+".jpg", i, j);
                tile.addActionListener(this);
                tiles.add(tile);
                id++;
            }
        }
        blankTile = new TilePiece("blank_tile.jpg", 0, 0);
        tiles.set(0, blankTile);
    }

    public void actionPerformed(ActionEvent e)
    {
        TilePiece t = (TilePiece) e.getSource();    // Get an object reference to the tile which has been pressed
        t.exchangeImageWith(blankTile);
        blankTile = t;
        // your gameplay code goes here

    }
}
