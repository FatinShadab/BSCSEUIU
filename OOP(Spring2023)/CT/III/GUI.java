import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI{
    JFrame window = new JFrame("Simple Calculator");

    JButton outputLabel_1= new JButton();
    JButton outputLabel_2 = new JButton();

    JButton one = new JButton();
    JButton two = new JButton();
    JButton three = new JButton();
    JButton four = new JButton();

    JButton add = new JButton();
    JButton sub = new JButton();
    JButton eq = new JButton();

    String output_1 = "";
    String output_2 = "";

    boolean op_used = false;
    boolean add_used = false;

    public GUI(){
        window.setLocation(100, 100);
        window.setSize(270, 480);

        outputLabel_1.setText(output_1);
        outputLabel_1.setEnabled(false);
        outputLabel_1.setLocation(30, 20);
        outputLabel_1.setSize(190, 40);

        outputLabel_2.setText(output_2);
        outputLabel_2.setEnabled(false);
        outputLabel_2.setLocation(50, 315);
        outputLabel_2.setSize(150, 45);

        add.setText("+");
        add.setLocation(50, 190);
        add.setSize(50, 50);
        add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (!op_used){
                    output_1 = output_1 + "+";
                    outputLabel_1.setText(output_1);
                    op_used = true;
                    add_used = true;
                }
            }
        });

        sub.setText("-");
        sub.setLocation(150, 190);
        sub.setSize(50, 50);
        sub.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (!op_used){
                    output_1 = output_1 + "-";
                    outputLabel_1.setText(output_1);
                    op_used = true;
                    add_used = false;
                }
            }
        });

        eq.setText("=");
        eq.setLocation(95, 255);
        eq.setSize(60, 50);
        eq.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                op_used = false;
                int lo, ro;

                if (add_used){
                    String[] oparands = output_1.split("\\+");
                    lo = Integer.parseInt(oparands[0]);
                    ro = Integer.parseInt(oparands[1]);

                } else {
                    String[] oparands = output_1.split("-");
                    lo = Integer.parseInt(oparands[0]);
                    ro = Integer.parseInt(oparands[1]);
                }

                int result = (add_used) ?   lo + ro : lo - ro;

                output_2 = ""+result;
                output_1 = "";

                outputLabel_1.setText(output_1);
                outputLabel_2.setText(output_2);

                add_used = false;
            }
        });

        one.setText("1");
        one.setLocation(50, 70);
        one.setSize(50, 50);
        one.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                output_1 += "1";
                outputLabel_1.setText(output_1);
            }
        });

        two.setText("2");
        two.setLocation(150, 70);
        two.setSize(50, 50);
        two.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                output_1 += "2";
                outputLabel_1.setText(output_1);
            }
        });

        three.setText("3");
        three.setLocation(50, 130);
        three.setSize(50, 50);
        three.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                output_1 += "3";
                outputLabel_1.setText(output_1);
            }
        });

        four.setText("4");
        four.setLocation(150, 130);
        four.setSize(50, 50);
        four.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                output_1 += "4";
                outputLabel_1.setText(output_1);
            }
        });


        // Adding Components according the layout
        window.add(outputLabel_1);

        window.add(one);
        window.add(two);
        window.add(three);
        window.add(four);

        window.add(add);
        window.add(sub);
        window.add(eq);

        window.add(outputLabel_2);


        window.setLayout(null);
        window.setVisible(true);
    }

    public static void main(String[] args){
        new GUI();
    }
}