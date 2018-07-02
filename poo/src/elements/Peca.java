/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elements;

import java.util.Random;

/**
 *
 * @author 7062145
 */
public class Peca {
    protected int[] pecaX;
    protected int[] pecaY;
    protected int tipo;
    protected int pos;
    public Peca nextPeca;
    
    
    public Peca(){
        pecaX = new int[4];
        pecaY = new int[4];
    }
    
    public void girar(int[][] pit, String tipo){
        for (int i=0;i<4;i++){
            pit[this.pecaY[i]][this.pecaX[i]] = 0;
        }
        
        //pos = (pos+1)%4;
            
        switch(tipo){
            case "PecaI":
                ((PecaI) this).girar(pit);
                break;
            case "PecaJ":
                ((PecaJ) this).girar(pit);
                break;
            case "PecaL":
                ((PecaL) this).girar(pit);
                break;
           case "PecaS":
                ((PecaS) this).girar(pit);
                break;
           case "PecaT":
                ((PecaT) this).girar(pit);
                break;
           case "PecaZ":
                ((PecaZ) this).girar(pit);
                 break;
        }
        
    }
    
    public static Peca randPeca(){
        Random rand = new Random();
        int x = rand.nextInt(7);
        switch(x){
            case 0:
                return new PecaL(x);
            case 1:
                return new PecaJ(x);
            case 2:
                return new PecaS(x);
            case 3:
                return new PecaZ(x);
            case 4:
                return new PecaO(x);
            case 5:
                return new PecaT(x);
            case 6:
                return new PecaI(x);
        }
        
        return null;
    }
    
    public int[][] printPeca(int[][] pit){
        for (int i=0 ; i<4 ; i++)
            pit[this.pecaY[i]][this.pecaX[i]] = 2;// quando é peca é 2.
        return pit;
    }
    
    public int[][] printNextPeca(int[][] pit){
        for (int i=0 ; i<4 ; i++)
            pit[(this.pecaY[i])+2][(this.pecaX[i])+11] = 2;// quando é peca é 2.
        return pit;
    }
    
    public int[][] fixaPeca(Peca peca, int[][] pit){
        
        for(int i=0 ; i<4 ; i++){
            pit[peca.pecaY[i]][peca.pecaX[i]] = 1;
        }
        return pit;
    }
       
    public Peca moveDown(int[][] pit) { 
        // VERIFICANDO COLISAO:
        Boolean bateu = false;
        for(int i=0 ; i<4 ; i++){
            if(pit[this.pecaY[i]+1][this.pecaX[i]] == 1){
                bateu = true;
            }
        }
        if(bateu == true){
            pit = this.fixaPeca(this, pit);
            Peca temp = new Peca();
            nextPeca.nextPeca = randPeca();
            temp = nextPeca;
            boolean endGame = false;
            
            for(int i=0; i<4 ; i++){
                if(pit[this.pecaX[i]][this.pecaY[i]] == 1)
                    endGame = true;
            }
            if(endGame == true)
                System.out.println("GAMER OVER OTARIO");
            return temp;
        }
        else{
            for(int i=0 ; i<4 ; i++){
                
                pit[this.pecaY[i]][this.pecaX[i]] = 0;
                this.pecaY[i] = this.pecaY[i]+1;
                
            }
        }
        
        return this;
    }
    
    public Peca turnDown(int[][] pit){
        Boolean bateu = false;
        
        while(!bateu){
            for(int i=0 ; i<4 ; i++){
                if(pit[this.pecaY[i]+1][this.pecaX[i]] == 1){
                    bateu = true;
                }
            }
            if(bateu == true){
                pit = this.fixaPeca(this, pit);
            Peca temp = new Peca();
            nextPeca.nextPeca = randPeca();
            temp = nextPeca;
            boolean endGame = false;
            
            for(int i=0; i<4 ; i++){
                if(pit[this.pecaX[i]][this.pecaY[i]] == 1)
                    endGame = true;
            }
            if(endGame == true)
                System.out.println("GAMER OVER OTARIO");
            return temp;
            }
            else{
                for(int i=0 ; i<4 ; i++){

                    pit[this.pecaY[i]][this.pecaX[i]] = 0;
                    this.pecaY[i] = this.pecaY[i]+1;

                }
            }
        }
        
        
        return this;
    }
    
    public int getTipo(Peca peca){
        return this.tipo;
    }
    
    public Peca turn(Peca peca){
        
        return peca;
    }
    
    public Peca moveUp(int[][] pit) {
        
        Peca temp = new Peca();
        for(int i=0 ; i<4 ; i++){
            
            temp.pecaX[i] = this.pecaX[i];
            temp.pecaY[i] = this.pecaY[i];
            
            if(this.pecaY[i] < 2 ){
                return this;
            }
            pit[this.pecaY[i]][this.pecaX[i]] = 0;
            temp.pecaY[i]--;
        }
        
        return temp;
    }
    
    public Peca moveLeft(int[][] pit) {
        
        //Peca temp = new Peca();
        boolean colisaoLateral = false;
        for(int i=0 ; i<4 ; i++){
            if(pit[this.pecaY[i]][this.pecaX[i]-1] == 1 )
                colisaoLateral = true;
        }
        if(colisaoLateral == true)
            return this;
        
        for(int i=0 ; i<4 ; i++){
            
            
            if(this.pecaX[i] < 2){
                return this;
            }
            //temp.pecaX[i] = this.pecaX[i];
            //temp.pecaY[i] = this.pecaY[i];
            pit[this.pecaY[i]][this.pecaX[i]] = 0;
            this.pecaX[i]--;
        }
        
        return this;
    }
    
    public Peca moveRight(int[][] pit) {
        
        
        
        boolean colisaoLateral = false;
        for(int i=0 ; i<4 ; i++){
            if(pit[this.pecaY[i]][this.pecaX[i]+1] == 1 )
                colisaoLateral = true;
        }
        if(colisaoLateral == true)
            return this;
        for(int i=0 ; i<4 ; i++){
                        
            if(this.pecaX[i] > 9){
                return this;
            }
            pit[this.pecaY[i]][this.pecaX[i]] = 0;
            this.pecaX[i]++;
        }
        
        return this;
    }
        
    public int randomize(){
        Random ran = new Random();
        int x = ran.nextInt(7);
        return x;
    }
    
    public Peca turnMatrix(Peca peca){
        int menorX=19, menorY=19;
        for(int i=0 ; i<4 ; i++){
            if(peca.pecaX[i] < menorX)
                menorX = peca.pecaX[i];
            if(peca.pecaY[i]< menorY)
                menorY = peca.pecaY[i];
        }
        for(int i=0 ; i<4 ; i++){
            peca.pecaX[i] = peca.pecaX[i] - menorX;
            peca.pecaY[i] = peca.pecaY[i] - menorY;            
        }
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                
            }
        }
        
        
        return peca;
    }
    
    public int[][] limpar(int[][] pit) {
        for (int i=4 ; i<10 ; i++){
            for(int z=11;z<20;z++){
               pit[i][z] = 1;
            }
        }
        return pit;
    }
}
