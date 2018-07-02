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
public class PecaT extends Peca{
    
    public PecaT(int x) {
        System.out.println("PecaT");
        this.pecaX[0] = 4;
        this.pecaX[1] = 5;
        this.pecaX[2] = 5;
        this.pecaX[3] = 6;
        
        this.pecaY[0] = 3;
        this.pecaY[1] = 3;
        this.pecaY[2] = 2;
        this.pecaY[3] = 3;
        
        this.tipo = x;
        this.pos = 0;
    }
    
    public void girar(int[][] pit) {
        switch(pos) {
            case 0:
                if(pit[this.pecaY[1]+1][this.pecaX[1]] == 1){}
                else{
                    this.pecaX[0] = this.pecaX[2];
                    this.pecaY[0] = this.pecaY[2];

                    this.pecaX[1] = this.pecaX[1];
                    this.pecaY[1] = this.pecaY[1];

                    this.pecaX[2] = this.pecaX[3];
                    this.pecaY[2] = this.pecaY[3];

                    this.pecaX[3] = this.pecaX[3]-1;
                    this.pecaY[3] = this.pecaY[3]+1;

                    this.pos = 1;
                }
                break;
            case 1:
                if(pit[this.pecaY[1]][this.pecaX[1]-1] == 1){}
                else{
                    this.pecaX[0] = this.pecaX[2];
                    this.pecaY[0] = this.pecaY[2];

                    this.pecaX[1] = this.pecaX[1];
                    this.pecaY[1] = this.pecaY[1];

                    this.pecaX[2] = this.pecaX[3];
                    this.pecaY[2] = this.pecaY[3];

                    this.pecaX[3] = this.pecaX[3]-1;
                    this.pecaY[3] = this.pecaY[3]-1;

                    this.pos = 2;
                }
                break;
            case 2:
                if(pit[this.pecaY[1]-1][this.pecaX[1]] == 1){}
                else{
                    this.pecaX[0] = this.pecaX[2];
                    this.pecaY[0] = this.pecaY[2];

                    this.pecaX[1] = this.pecaX[1];
                    this.pecaY[1] = this.pecaY[1];

                    this.pecaX[2] = this.pecaX[3];
                    this.pecaY[2] = this.pecaY[3];

                    this.pecaX[3] = this.pecaX[3]+1;
                    this.pecaY[3] = this.pecaY[3]-1;              

                    this.pos = 3;
                }
                break;
            case 3:
                if(pit[this.pecaY[1]][this.pecaX[1]+1] == 1){}
                else{
                    this.pecaX[0] = this.pecaX[2];
                    this.pecaY[0] = this.pecaY[2];

                    this.pecaX[1] = this.pecaX[1];
                    this.pecaY[1] = this.pecaY[1];

                    this.pecaX[2] = this.pecaX[3];
                    this.pecaY[2] = this.pecaY[3];

                    this.pecaX[3] = this.pecaX[3]+1;
                    this.pecaY[3] = this.pecaY[3]+1;             

                    this.pos = 0;
                }
                break;
        }        
    }   
}
    
    
    

