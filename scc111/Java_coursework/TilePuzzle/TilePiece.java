import javax.swing.*;
import java.awt.*;

/**
 * Represents an individual tile in a sliding tile puzzle.
 *
 * @see TilePuzzle
 */
public class TilePiece extends JButton
{
	private int xPos;
	private int yPos;

	private Icon solvedIcon;
	
	/**
	 * Creates an instance of a TilePiece.
	 *
	 * @param filename The filename of an image file to place on this tile
	 * @param x the x co-ord of this piece on the board (the column)
	 * @param y the y co-ord of this piece on the board (the row)
	 */
	public TilePiece(String filename, int x, int y)
	{
		super(new ImageIcon(filename));

		solvedIcon = this.getIcon();

		xPos = x;
		yPos = y;
	}

	/**
	 * Gets the x co-ordinate of this tile on the board (the column)
	 *
	 * @return the x co-ordinate of this tile.
	 */
	public int getXPos()
	{
		return xPos;
	}

	/**
	 * Gets the y co-ordinate of this tile on the board (the row)
	 *
	 * @return the y co-ordinate of this tile.
	 */
	public int getYPos()
	{
		return yPos;
	}

	/**
	 * Determines if a given TilePiece is adjacent to this TilePiece on the board.
	 * Tiles are known as adjacent if they are next to each other either horizontally
	 * or vertically.
	 *
	 * @param p The TilePiece to compare to
	 * @return True if the Tiles are adjacent, false otherwise
	 */
	public boolean isAdjacentTo(TilePiece p)
	{

		if (((p.getXPos() == xPos) && Math.abs(p.getYPos() - yPos) == 1) ||
		    ((p.getYPos() == yPos) && Math.abs(p.getXPos() - xPos) == 1))
			return true;

		return false;
	}

	/**
	 * Exchanges the image stored on this tile with the given tile.
	 *
	 * @param p The tile to exchange images with.
	 */
	public void exchangeImageWith(TilePiece p)
	{
		Icon otherIcon = p.getIcon();		// Store an object reference to the image on the given tile 
		Icon ourIcon = this.getIcon();		// Store an object reference to the image on our tile 

		p.setIcon(ourIcon);			// Swap the image on the given tile
		this.setIcon(otherIcon);		// with the one on our tile
	}

	/**
	 * Determines if this tile is in its correct (solved position). 
	 * This method assumes that the puzzle is generated in the completed position.
	 */
	public boolean isCorrect()
	{
		return this.getIcon() == solvedIcon;
	}
}
