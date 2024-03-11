import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.File;
import java.util.concurrent.CompletableFuture;

public class PlayerWindow extends JFrame implements ActionListener
{
    private JPanel factPanel;
    private JPanel categoryPanel;
    private JPanel mainPanel;
    private TopTrumps game;

    private JButton[] buttons = new JButton[5];
    private JLabel[] values = new JLabel[5];
    private JLabel title;
    private JLabel cardNameLabel;
    private JLabel cardNameValue;
    private JLabel cardImage;
    private Player player;

    public PlayerWindow(TopTrumps game, Player p)
    {
        this.game = game;
        this.player = p;

        mainPanel = new JPanel();

        factPanel = new JPanel();
        factPanel.setLayout(new BorderLayout());

        categoryPanel = new JPanel();
        categoryPanel.setLayout(new GridLayout(6,2));

        title = new JLabel(player.getPlayerName() + ": ");
        cardNameLabel = new JLabel("Name: ");
        cardNameValue = new JLabel(" --- ");

        cardImage = new JLabel(new ImageIcon("Unknown.jpg"));

        categoryPanel.add(cardNameLabel);
        categoryPanel.add(cardNameValue);

        buttons[0] = new JButton("Speed");
        buttons[1] = new JButton("Weight");
        buttons[2] = new JButton("Era");
        buttons[3] = new JButton("Legs");
        buttons[4] = new JButton("Wings");

        for (int i=0; i<5; i++)
        {
            values[i] = new JLabel("  ---  ");
            buttons[i].addActionListener(this);
            categoryPanel.add(buttons[i]);
            categoryPanel.add(values[i]);
        }    

        factPanel.add(title, BorderLayout.NORTH);
        factPanel.add(categoryPanel, BorderLayout.CENTER);

        mainPanel.setLayout(new BorderLayout());
        mainPanel.add(cardImage, BorderLayout.CENTER);
        mainPanel.add(factPanel, BorderLayout.SOUTH);

        this.setContentPane(mainPanel);
		this.setTitle("Top Trumps Dinosaurs!");
		this.setSize(400,400);
        this.enableButtons(false);
		this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
    }

    public void enableButtons(boolean b)
    {
        for (int i=0; i<buttons.length; i++)
            buttons[i].setEnabled(b);
    }

    public void hideCard()
    {
        cardNameValue.setText("  ---  ");

        for (int i=0; i<values.length; i++)
            values[i].setText("  ---  ");
    }

    public void showCard()
    {
        Card c = player.getCurrentCard();
        String imageFilename = c.getName()+".jpg";        
        File tmp = new File(imageFilename);

        if (tmp.exists() == false)
            imageFilename = "Unknown.jpg";
        
        cardNameValue.setText("   " + c.getName());
        cardImage.setIcon(new ImageIcon(imageFilename));

        for (int i=0; i<values.length; i++)
            values[i].setText("  " + c.getCategory(buttons[i].getText()).getValue());
    }

    public void updateCard(Player p)
    {
        if (player == p)
            this.showCard();
        else
            this.hideCard();
    }

    public void changeTurn(Player p)
    {
        if (player == p)
        {
            title.setText(player.getPlayerName() + ": YOUR TURN!");
            this.enableButtons(true);
        }
        else
        {
            title.setText(player.getPlayerName() + ":");
            this.enableButtons(false);
        }
    }

    public void gameOver(Player winningPlayer)
    {
        if (winningPlayer == player)
            title.setText(" ---- YOU WIN!! ----");
        else
            title.setText(" ---- YOU LOSE!! ----");

        this.enableButtons(false);
    }

    public void actionPerformed(ActionEvent event)
	{
        String categoryName = ((JButton)event.getSource()).getText();

        // You may assume that this code simply calls the following method: 
        //    game.categorySelected(categoryName);
        //
        // You can safely ignore runAsync() code and additional syntax for this exercise.
        // it is not relevant to your task.
        //
		// -- Joe
        if (game.isWaitingForPlayer())
            CompletableFuture.runAsync(() -> {game.categorySelected(categoryName);});
	}
}