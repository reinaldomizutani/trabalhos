/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elements;

import utils.Consts;


public class PecaI extends Peca{
    
    public PecaI(int x) {
        System.out.println("PecaI");
        this.pecaX[0] = 5;
        this.pecaX[1] = 5;
        this.pecaX[2] = 5;
        this.pecaX[3] = 5;
        
        this.pecaY[0] = 2;
        this.pecaY[1] = 3;
        this.pecaY[2] = 4;
        this.pecaY[3] = 5;
        
        this.tipo = x;
        this.pos = 0;
    }
    
    @SuppressWarnings("empty-statement")
    public void girar(int[][] pit) {
        switch(pos) {
            case 0:
                if(pit[this.pecaY[1]][this.pecaX[1]+2] == 1){}
                else if(pit[this.pecaY[1]][this.pecaX[1]+1] == 1){}
                else if(pit[this.pecaY[1]][this.pecaX[1]-1] == 1){}
                else{
                    
                    this.pecaX[0] = this.pecaX[0]+2;
                    this.pecaX[1] = this.pecaX[1]+1;
                    this.pecaX[2] = this.pecaX[2];
                    this.pecaX[3] = this.pecaX[3]-1;

                    this.pecaY[0] = this.pecaY[0]+1;
                    this.pecaY[1] = this.pecaY[1];
                    this.pecaY[2] = this.pecaY[2]-1;
                    this.pecaY[3] = this.pecaY[3]-2;
                    this.pos = 1;
                }
                break;
            case 1:
                
                if(pit[this.pecaY[2]+2][this.pecaX[2]] == 1){}
                else if(pit[this.pecaY[2]+1][this.pecaX[2]] == 1){}
                
                else{
                System.out.println("case1 pecaI");
                this.pecaX[0] = this.pecaX[0]-2;
                this.pecaX[1] = this.pecaX[1]-1;
                this.pecaX[2] = this.pecaX[2];
                this.pecaX[3] = this.pecaX[3]+1;

                this.pecaY[0] = this.pecaY[0]-1;
                this.pecaY[1] = this.pecaY[1];
                this.pecaY[2] = this.pecaY[2]+1;
                this.pecaY[3] = this.pecaY[3]+2;
                this.pos = 0;
                break;
                }
            
        }
        
    }
      
}
    
    
    

