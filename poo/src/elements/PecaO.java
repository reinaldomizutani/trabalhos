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
public class PecaO extends Peca{
    
    public PecaO(int x) {
        System.out.println("PecaO");
        this.pecaX[0] = 5;
        this.pecaX[1] = 5;
        this.pecaX[2] = 6;
        this.pecaX[3] = 6;
        
        this.pecaY[0] = 2;
        this.pecaY[1] = 3;
        this.pecaY[2] = 2;
        this.pecaY[3] = 3;
        
        this.tipo = x;
        this.pos = 0;
    } 
}
    
    
    

