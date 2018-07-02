/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elements;

import utils.Consts;
/**
 *
 * @author 7062145
 */
public class PecaS extends Peca{
    
    public PecaS(int x) {
        System.out.println("PecaS");
        this.pecaX[0] = 4;
        this.pecaX[1] = 5;
        this.pecaX[2] = 5;
        this.pecaX[3] = 6;
        
        this.pecaY[0] = 4;
        this.pecaY[1] = 4;
        this.pecaY[2] = 3;
        this.pecaY[3] = 3;
        
        this.tipo = x;
        this.pos = 0;
    }
    
    
    public void girar(int[][] pit) {
        switch(pos) {
            case 0:
                if(pit[this.pecaY[3]+2][this.pecaX[3]] == 1){}
                else if(pit[this.pecaY[3]+1][this.pecaX[3]] == 1){}
                else{
                    this.pecaX[0] = this.pecaX[0]+2;
                    this.pecaY[0] = this.pecaY[0]+1;

                    this.pecaX[1] = this.pecaX[1]+1;
                    this.pecaY[1] = this.pecaY[1];

                    this.pecaX[2] = this.pecaX[2];
                    this.pecaY[2] = this.pecaY[2]+1;

                    this.pecaX[3] = this.pecaX[3]-1;
                    this.pecaY[3] = this.pecaY[3];            

                    this.pos = 1;       
                }
                break;
            case 1:
                if(pit[this.pecaY[2]][this.pecaX[2]-1] == 1){}
                    else if(pit[this.pecaY[3]][this.pecaX[3]+1] == 1){}
                    else{
                        this.pecaX[0] = this.pecaX[0]-2;
                        this.pecaY[0] = this.pecaY[0]-1;

                        this.pecaX[1] = this.pecaX[1]-1;
                        this.pecaY[1] = this.pecaY[1];

                        this.pecaX[2] = this.pecaX[2];
                        this.pecaY[2] = this.pecaY[2]-1;

                        this.pecaX[3] = this.pecaX[3]+1;
                        this.pecaY[3] = this.pecaY[3];            

                        this.pos = 0;   
                    }
                break;
            
        }
        
    }
    
}
    
    
    

