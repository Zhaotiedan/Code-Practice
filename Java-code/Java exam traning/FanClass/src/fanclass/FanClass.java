
package fanclass;
public class FanClass {
    
    static final int SLOW=1;
    static final int MEDIUM=2;
    static final int FAST=3;
    private int speed=SLOW;//默认值
    private boolean on =false;
    private double radius=5;
    private String color ="blue";
    public FanClass(){
        
    }
    public int getSpeed() {
	return speed;
    }
    public void setSpeed(int speed) {
	this.speed = speed;
    }
    public boolean isOn() {
	return on;
    }
    public void setOn(boolean on) {
	this.on = on;
    }
    public double getRadius() {
	return radius;
    }
    public void setRadius(double radius) {
	this.radius = radius;
    }

    public String getColor() {
	return color;
    }
    public void setColor(String color) {
	this.color = color;
    }
    public String tostring(){
        if(on)
            return "speed: " + speed + " color: " + color + " radius: " + radius;
        else
            return "fan is off " + " color: " + color + " radius: " + radius;
    }


    public static void main(String[] args) {
        FanClass fan1=new FanClass();
        fan1.setSpeed(FAST);
        fan1.setRadius(10);
        fan1.setColor("yellow");
        fan1.setOn(true);
        
        FanClass fan2=new FanClass();
        fan2.setSpeed(MEDIUM);
        fan2.setRadius(5);
        fan2.setColor("blue");
        fan2.setOn(false);
        
        System.out.println("fan1:" + fan1.tostring());
        System.out.println("fan2:" + fan2.tostring());
    }
    
}
