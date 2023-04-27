/*
For the following GUI question, write a single code to answer both a & b.
    a) Complete the following code to create a GUI as shown in image 1. Assume all necessary classes are
        imported
    b) Providebuttonclickhandlingcodesothatwhenbutton1(top-left)ispressed,thebuttonsshowtextslike
    image 1. When button 4 (bottom-right) is pressed, the buttons show texts like image 2
*/
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class GUI{
    public static void main(String[] args){
        JFrame frame = new JFrame("My App");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);
        
        // solution code
        frame.setLayout(new GridLayout(2, 2));

        JButton top_left_btn = new JButton("1");
        JButton top_right_btn = new JButton("2");
        JButton bottom_left_btn = new JButton("3");
        JButton bottom_right_btn = new JButton("4");

        top_left_btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                top_right_btn.setText("2");
                bottom_left_btn.setText("3");   
            }
        });
        
        bottom_right_btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                top_right_btn.setText("3");
                bottom_left_btn.setText("2");  
            }
        });

        frame.add(top_left_btn);
        frame.add(top_right_btn);
        frame.add(bottom_left_btn);
        frame.add(bottom_right_btn);

        frame.setVisible(true);
    }
}