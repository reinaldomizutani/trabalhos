package control;

import elements.Peca;
import java.awt.Font;
import utils.Consts;
import utils.Drawing;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 * Projeto de POO 2017
 * 
 * @author Luiz Eduardo
 * Baseado em material do Prof. Jose Fernando Junior
 */
public class GameScreen extends javax.swing.JFrame implements KeyListener {
    
    //private final Lolo lolo;
    //private final ArrayList<Element> elemArray;
    //private final GameController controller = new GameController();
    
    private int cont=0;
    private int[][] pit;
    private Peca peca;
    private int delay=0;
    private int delayMax =50;
    private int pontoMax =1000;
    //private Peca proxPeca;
    private int[][] aux;
    private int pontos;
    public static int contlinha;
    
    public GameScreen() {
        peca = Peca.randPeca();
        peca.nextPeca = Peca.randPeca();
        pontos = 0;
        // i = altura
        // j = largura
        pit = new int[Consts.NUM_CELLS][Consts.NUM_CELLS];
        for(int i=0 ; i<Consts.NUM_CELLS ; i++){
            for(int j=0 ; j<Consts.NUM_CELLS ; j++){
                if(i > 0 && i < 19 && j>0 && j<11 )
                    pit[i][j] = 0;
                else
                    pit[i][j] = 1;
                
            }
        }
        Drawing.setGameScreen(this);
        initComponents();
        
        this.addKeyListener(this);   /*teclado*/
        
        /*Cria a janela do tamanho do tabuleiro + insets (bordas) da janela*/
        this.setSize(Consts.NUM_CELLS * Consts.CELL_SIZE + getInsets().left + getInsets().right,
                     Consts.NUM_CELLS * Consts.CELL_SIZE + getInsets().top + getInsets().bottom);


    }
    /*
    public final void addElement(Element elem) {
        elemArray.add(elem);
    }
    
    public void removeElement(Element elem) {
        elemArray.remove(elem);
    }
    */
    @Override
    public void paint(Graphics gOld) {
        
        
        
        Graphics g = getBufferStrategy().getDrawGraphics();
        Graphics g2 = g.create(getInsets().right, getInsets().top, getWidth() - getInsets().left, getHeight() - getInsets().bottom);
        
        /* DESENHA CENARIO
           Trocar essa parte por uma estrutura mais bem organizada
           Utilizando a classe Stage
        */
              
        
        for (int i = 0; i < Consts.NUM_CELLS; i++) {
            for (int j = 0; j < (Consts.NUM_CELLS)-8; j++) {
                try {

                    Image preto = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "screen.png");
                    Image branco1 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "blocoWall.png");
                    Image branco2 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "bloco.png");
                    Image branco2c = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "bloco.png");
                    Image branco2tipo0 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo0.png");
                    Image branco2tipo1 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo1.png");
                    Image branco2tipo2 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo2.png");
                    Image branco2tipo3 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo3.png");
                    Image branco2tipo4 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo4.png");
                    Image branco2tipo5 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo5.png");
                    Image branco2tipo6 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "tipo6.png");
                    if(pit[i][j] == 0){
                        g2.drawImage(preto,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 1 && i!=0 && i!=19 && j != 0 && j != 11 && j != 12){
                        g2.drawImage(branco2c,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(i == 0 || i == 19 || j == 0 || j == 11 || j == 12){
                        g2.drawImage(branco1,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    //___________________________________________PINTA PEÇAS________________________________________________________________________
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 1 && peca.getTipo(peca) != 2 && peca.getTipo(peca) != 3 && peca.getTipo(peca) != 4 && peca.getTipo(peca) != 5 && peca.getTipo(peca) != 6){
                        g2.drawImage(branco2tipo0,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 0 && peca.getTipo(peca) != 2 && peca.getTipo(peca) != 3 && peca.getTipo(peca) != 4 && peca.getTipo(peca) != 5 && peca.getTipo(peca) != 6){
                        g2.drawImage(branco2tipo1,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 1 && peca.getTipo(peca) != 0 && peca.getTipo(peca) != 3 && peca.getTipo(peca) != 4 && peca.getTipo(peca) != 5 && peca.getTipo(peca) != 6){
                        g2.drawImage(branco2tipo2,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 1 && peca.getTipo(peca) != 2 && peca.getTipo(peca) != 0 && peca.getTipo(peca) != 4 && peca.getTipo(peca) != 5 && peca.getTipo(peca) != 6){
                        g2.drawImage(branco2tipo3,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 1 && peca.getTipo(peca) != 2 && peca.getTipo(peca) != 3 && peca.getTipo(peca) != 0 && peca.getTipo(peca) != 5 && peca.getTipo(peca) != 6){
                        g2.drawImage(branco2tipo4,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 1 && peca.getTipo(peca) != 2 && peca.getTipo(peca) != 3 && peca.getTipo(peca) != 4 && peca.getTipo(peca) != 0 && peca.getTipo(peca) != 6){
                        g2.drawImage(branco2tipo5,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                    else if(pit[i][j] == 2 && peca.getTipo(peca) != 1 && peca.getTipo(peca) != 2 && peca.getTipo(peca) != 3 && peca.getTipo(peca) != 4 && peca.getTipo(peca) != 5 && peca.getTipo(peca) != 0){
                        g2.drawImage(branco2tipo6,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                    }
                } catch (IOException ex) {
                    Logger.getLogger(GameScreen.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            }
        }
        
        for (int i = 0; i < Consts.NUM_CELLS; i++) {
            for (int j = (Consts.NUM_CELLS)-8; j < (Consts.NUM_CELLS); j++) {
                try {
                    Image branco3 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "branco.png");
                    Image branco2 = Toolkit.getDefaultToolkit().getImage(new java.io.File(".").getCanonicalPath() + Consts.IMG_PATH + "bloco.png"); 
                    if(pit[i][j] == 1){
                        g2.drawImage(branco3,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                     }else{
                         g2.drawImage(branco2,
                                j * Consts.CELL_SIZE, i * Consts.CELL_SIZE, Consts.CELL_SIZE, Consts.CELL_SIZE, null);
                     }
                } catch (IOException ex) {
                    Logger.getLogger(GameScreen.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
        
        
        
        
        
        
        /* Imprimindo Pontuação na Tela*/
        Font f1 = new Font("Oswald", Font.BOLD, 14);
        String pont = Integer.toString(this.getPontos());
        g2.setFont(f1);
        g2.drawString("Pontos",450,35);
        g2.drawString(pont, 450, 55);
        g2.drawString("Próxima Peça",450,80);
        pit = peca.limpar(pit);
        pit = peca.nextPeca.printNextPeca(pit);
        pit = peca.printPeca(pit);
        //g.dispose();
        //g2.dispose();
        if (!getBufferStrategy().contentsLost()) {
            getBufferStrategy().show();
        }
    }

    public int getPontos() {
        return pontos;
    }
    
    public void go() {
        TimerTask task = new TimerTask() {
            
            public void run() {
                repaint();
                int linhas,tempPtos;                
                if(delay == delayMax){
                    if(pontos >= pontoMax && delayMax > 15){
                        delayMax=(int)(delayMax*0.7);
                        pontoMax =pontoMax+1000;
                    }
                    
                    linhas = eliminarLinha(pit);
                    peca = peca.moveDown(pit);
                    if(linhas == 1)
                        pontos = pontos + 50;
                    else if(linhas == 2)
                        pontos = pontos + 50*4;
                    else if(linhas == 3)
                        pontos = pontos + 50*16;
                    else if(linhas ==4)
                        pontos = pontos + 50*64;
                    
                    System.out.println("pontos = " + pontos);
                    delay=0;
                }
                delay++;
            }
        };
        Timer timer = new Timer();
        timer.schedule(task, 0, Consts.DELAY_SCREEN_UPDATE);
    }
    
    public static int eliminarLinha(int[][] matrizTela){
        int completos=0;
        contlinha=0;
        int [][] aux = new int[20][12];
        
        for(int z=0;z<20;z++){
            for(int t=0;t<12;t++){
                aux[z][t] = matrizTela[z][t];
            }
        }
        
        
        for(int i=18;i>0;i--){
            for(int j=1;j<11;j++){
                if(matrizTela[i][j] == 1){
                    completos++;
                }
                
                if(completos >= 10){                  
                    contlinha++;
                    System.out.println("Eliminar linha:" + i);
                        int row = i;
                        for (int k = row-1; k > 0; k--) {
                            for (j = 0; j < 12; j++){
                                matrizTela[k+1][j] = matrizTela[k][j];
                            }
                        }
                    }
                }
            completos=0;
        }
        System.out.println("Linhas Finais: "+ contlinha);
        return contlinha;
    }
    
    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_UP) {
            peca.girar(pit,peca.getClass().getSimpleName());
        } else if (e.getKeyCode() == KeyEvent.VK_DOWN) {
            peca = peca.moveDown(pit);
        } else if (e.getKeyCode() == KeyEvent.VK_LEFT) {
            peca = peca.moveLeft(pit);
        } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
            peca = peca.moveRight(pit);
        } else if (e.getKeyCode() == KeyEvent.VK_SPACE){
            peca = peca.turnDown(pit);
        }

        
        //repaint(); /*invoca o paint imediatamente, sem aguardar o refresh*/
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("TETRIS - TRABALHO DE POO");
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        setLocation(new java.awt.Point(20, 20));
        setResizable(false);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 500, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 500, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
    
    @Override
    public void keyTyped(KeyEvent e) {
    }
    
    @Override
    public void keyReleased(KeyEvent e) {
    }
}
