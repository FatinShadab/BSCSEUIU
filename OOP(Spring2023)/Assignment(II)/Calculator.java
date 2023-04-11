import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator{
    JFrame window = new JFrame("Simple Calculator");

    JTextArea input_1 = new JTextArea();
    JTextArea input_2 = new JTextArea();

    JButton addButton = new JButton();
    JButton subButton = new JButton();
    JButton mulButton = new JButton();
    JButton divButton = new JButton();

    JButton outputArea = new JButton();

    public Calculator(){
        window.setLocation(50, 50);
        window.setSize(270, 480);

        input_1.setLocation(50, 20);
        input_1.setSize(70, 40);

        input_2.setLocation(150, 20);
        input_2.setSize(70, 40);

        addButton.setText("+");
        addButton.setLocation(60, 70);
        addButton.setSize(45, 40);
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int left_oparand   = Integer.parseInt(input_1.getText());
                int right_oparand  = Integer.parseInt(input_2.getText());

                outputArea.setText(""+(left_oparand+right_oparand));
            }
        });

        subButton.setText("-");
        subButton.setLocation(160, 70);
        subButton.setSize(40, 40);
        subButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int left_oparand   = Integer.parseInt(input_1.getText());
                int right_oparand  = Integer.parseInt(input_2.getText());

                outputArea.setText(""+(left_oparand-right_oparand));
            }
        });

        mulButton.setText("x");
        mulButton.setLocation(60, 120);
        mulButton.setSize(45, 40);
        mulButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int left_oparand   = Integer.parseInt(input_1.getText());
                int right_oparand  = Integer.parseInt(input_2.getText());

                outputArea.setText(""+(left_oparand*right_oparand));
            }
        });

        divButton.setText("/");
        divButton.setLocation(160, 120);
        divButton.setSize(40, 40);
        divButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int left_oparand   = Integer.parseInt(input_1.getText());
                int right_oparand  = Integer.parseInt(input_2.getText());

                outputArea.setText(""+(left_oparand/right_oparand));
            }
        });

        outputArea.setText("");
        outputArea.setEnabled(false);
        outputArea.setLocation(80, 170);
        outputArea.setSize(100, 40);

        window.add(input_1);
        window.add(input_2);
        window.add(addButton);
        window.add(subButton);
        window.add(mulButton);
        window.add(divButton);
        window.add(outputArea);

        window.setLayout(null);
        window.setVisible(true);
    }

    public static void main(String[] args){
        new Calculator();
    }
}