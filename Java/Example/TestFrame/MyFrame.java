package MyCode.Java.Example.TestFrame;
import javax.swing.*;

public class MyFrame {
    public static void main(String[] args){
        JFrame frame = new JFrame("My First Frame");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
