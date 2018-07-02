package control;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import jpanelmenu.JPanelMenu;

/**
 * Projeto de POO 2017
 *
 * @author Luiz Eduardo Baseado em material do Prof. Jose Fernando Junior
 */
public class Main implements ActionListener {

    JButton fase1 = new JButton("Fase 1");
    JButton fase2 = new JButton("Fase 2");
    JButton load = new JButton("Load");
    JPanelMenu panel = new JPanelMenu();
    JFrame frame = new JFrame();

    public Main() {
        frame.add(panel);
        panel.add(fase1);
        panel.add(fase2);
        panel.add(load);
        
        frame.setSize(355, 550);
        frame.setVisible(true);
        fase1.addActionListener(this);

        fase1.setBounds(120, 150, 80, 30);
        fase2.setBounds(120, 200, 80, 30);
        load.setBounds(120, 250, 80, 30);

        
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == fase1) {
            java.awt.EventQueue.invokeLater(new Runnable() {
                @Override
                public void run() {
                    GameScreen screen = new GameScreen();
                    screen.setVisible(true);
                    screen.createBufferStrategy(2);
                    screen.go();
                    frame.setVisible(false);
                }
            });

        } else if (e.getSource() == fase2) {

        } else if (e.getSource() == load) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {

        Main t1 = new Main();

    }

}
