import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI implements ActionListener{

    JFrame window        = new JFrame();

    JLabel userName      = new JLabel("User Name");
    JTextArea unameInp   = new JTextArea();

    JLabel password      = new JLabel("Password");
    JPasswordField pwInp = new JPasswordField();

    JButton loginBtn     = new JButton("Login");

    String defaultUname  = "ADMIN";
    String defaultPW     = "123";

    public GUI(){
        window.setLocation(50, 50);
        window.setSize(600, 600);
        window.setLayout(null);

        userName.setBounds(150, 150, 200, 20);
        unameInp.setBounds(250, 150, 200, 20);

        password.setBounds(150, 200, 200, 20);
        pwInp.setBounds(250, 200, 200, 20);
        pwInp.setEchoChar('#');

        loginBtn.setBounds(250, 250, 80, 40);
        loginBtn.addActionListener(this);

        window.add(userName);
        window.add(unameInp);

        window.add(password);
        window.add(pwInp);

        window.add(loginBtn);

        window.setVisible(true);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (unameInp.getText().equals(defaultUname) && new String(pwInp.getPassword()).equals(defaultPW)){
            System.out.println("Success !");
        } else {
            System.out.println("Not Success !");
        }
    }

    public static void main(String[] args) {
        new GUI();
    }
}
