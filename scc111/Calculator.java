import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class UI {

    public UI(){
        JFrame mainFrame = new JFrame("Calculator");
        JPanel mainPanel = new JPanel();
        JPanel inputPanel = new JPanel();
        JTextField input1 = new JTextField("",10);
        JTextField input2 = new JTextField("",10);
        JButton button = new JButton("Calculate!");
        JLabel resultLabel = new JLabel("Results: ");

        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        inputPanel.setLayout(new BoxLayout(inputPanel, BoxLayout.X_AXIS));
        inputPanel.add(input1);
        inputPanel.add(input2);
        mainPanel.add(inputPanel);
        mainPanel.add(button);
        mainPanel.setBorder(new EmptyBorder(10,10,10,10));
        resultLabel.setBorder(new EmptyBorder(5,5,5,5));
        mainPanel.add(resultLabel);
        mainFrame.setContentPane(mainPanel);
        mainFrame.setSize(300,100);

        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setVisible(true);

        button.addActionListener(e -> {
            int result = Calculate(Integer.parseInt(input1.getText()), Integer.parseInt(input2.getText()));
            resultLabel.setText("Result: " + result);
        });
    }

    private int Calculate(int n1, int n2){
        return n1 + n2;
    }
}
