import java.util.concurrent.TimeUnit;

public class TopTrumps
{
	private Player player, opponent;
	private PlayerWindow[] windows;
	private int totalCards = 10;
	private boolean waitingForPlayer = true;
	
	public TopTrumps()
	{
		opponent = new Player("Player 1", totalCards);
		player = new Player("Player 2", totalCards);

		player.addCard(new Card("Gigantosaurus", 20, 8000, 75, 2, 0));
		player.addCard(new Card("Stegosaurus", 4, 3100, 76, 4, 0));
		player.addCard(new Card("Troodon", 22, 40, 72, 2, 0));
		player.addCard(new Card("Archaeopteryx", 21, 2, 213, 2, 2));
		player.addCard(new Card("Desplatosaurus", 28, 6100, 85, 2, 0));

		opponent.addCard(new Card("Coelophysis", 10, 27, 225, 2, 0));
		opponent.addCard(new Card("T-Rex", 30, 7000, 65, 2, 0)); 
		opponent.addCard(new Card("Diplodocus", 2, 80000, 115, 4, 0));
		opponent.addCard(new Card("Pteranodon", 35, 45, 125, 2, 2));
		opponent.addCard(new Card("Doyouthinkhesaurus", 100, 0, 0, 2, 0));

		windows = new PlayerWindow[2];
		windows[0] = new PlayerWindow(this, player);
		windows[1] = new PlayerWindow(this, opponent);

		this.swapTurn();
		this.nextTurn();
	}

	public void swapTurn()
	{
		Player tmp = player;
		player = opponent;
		opponent = tmp;

		for (int i=0; i<windows.length; i++)
			windows[i].changeTurn(player);
	}
	
	public void nextTurn()
	{
        player.nextCard();
        opponent.nextCard();

		for (int i=0; i<windows.length; i++)
			windows[i].updateCard(player);
	}

	public void categorySelected(String categoryName)
	{
		waitingForPlayer = false;

		for (int i=0; i<windows.length; i++)
			windows[i].showCard();

		this.delay(3);

        if (!player.getCurrentCard().isBetterThan(opponent.getCurrentCard(), categoryName))
            this.swapTurn();

		player.addCard(opponent.getCurrentCard());
		opponent.removeCard(opponent.getCurrentCard());

		if (player.hasWon())
        {
			for (int i=0; i<windows.length; i++)
				windows[i].gameOver(player);
        }

		this.nextTurn();

		waitingForPlayer = true;
	}

	public void delay(int seconds)
	{
		// This code simply delays for the given number of seconds.
		// You can ignore the try/catch keywords.
		// We will be learning about these in lecture soon. :)
		// -- Joe

		try {
			TimeUnit.SECONDS.sleep(seconds);
		} catch(InterruptedException e) {}
	}

	public boolean isWaitingForPlayer()
	{
		return waitingForPlayer;
	}

	public static void main(String[] args)
	{
		TopTrumps t = new TopTrumps();
	}

}