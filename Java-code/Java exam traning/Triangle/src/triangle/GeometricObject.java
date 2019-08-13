/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package triangle;


class GeometricObject {
    private String color="white";
    private boolean filled=false;
    public GeometricObject(){
        
    }
    public GeometricObject(String color, boolean filled){
      this.color=color;
      this.filled=filled;
    }
    public String getColor(){
        return color;
    }
    public void setColor(String color){
        this.color=color;
    }
    public boolean isFilled(){
        return filled;
    }
    public void setFilled(boolean filled){
        this.filled=filled;
    }
    public String toString(){
        return "the color is " + color + "and filled: " + filled;
    }
}
