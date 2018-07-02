package utils;

import java.io.Serializable;

/**
 * Projeto de POO 2017
 * 
 * @author Luiz Eduardo
 * Baseado em material do Prof. Jose Fernando Junior
 */
public class Position implements Serializable {
    /* Elements are positioned in a grid layout (integers).
       
       x and y ranges from 0 to CELL_SIZE*NUM_CELLS.
       The real pixel positioning is converted by the Drawing class.
       As consequence, any element has size 1x1 (x and y). */
    
    public static final int WALK_STEP_DEC_PLACES = 10; // Auxiliary
    
    private int x;
    private int y;
    
    private int previousX;
    private int previousY;

    public Position(int x, int y){
        this.setPosition(x,y);
    }

    public final boolean setPosition(int x, int y){
        //int factor = (int)Math.pow(10, WALK_STEP_DEC_PLACES+1);
        //x = (double)Math.round(x * factor) / factor;
        //y = (double)Math.round(y * factor) / factor;
        
        if(x < 0 || x > utils.Consts.NUM_CELLS-1)
            return false;
        previousX = this.x;
        this.x = x;
        
        if(y < 0 || y > utils.Consts.NUM_CELLS-1)
            return false;
        previousY = this.y;
        this.y = y;
        return true;
    }
    
    public int getX(){
        return x;
    }
   
    public int getY(){
        return y;
    }

    public boolean comeBack(){
        return this.setPosition(previousX,previousY);
    }
    
    public boolean moveUp(){
        return this.setPosition(this.getX()-1, this.getY());
    }
    public boolean moveDown(){
        return this.setPosition(this.getX()+1, this.getY());
    }
    public boolean moveRight(){
        return this.setPosition(this.getX(), this.getY()+1);
    }
    public boolean moveLeft(){
        return this.setPosition(this.getX(), this.getY()-1);        
    }
}
