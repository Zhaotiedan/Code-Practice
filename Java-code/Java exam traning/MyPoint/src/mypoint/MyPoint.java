
package mypoint;


public class MyPoint {
    double x;
    double y;
    public MyPoint(){
        x=0;
        y=0;
    }
    public MyPoint(double x,double y){
        this.x=x;
        this.y=y;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    public double distance(double x, double y){
        return Math.sqrt((this.x-x)*(this.x-x)+(this.y-y)*(this.y-y));
    }
    public double distance(MyPoint point){
        return Math.sqrt((this.x-point.getX())*(this.x-point.getX())+(this.y-point.getY())*(this.y-point.getY()));
    }
    public static void main(String[] args) {
        MyPoint point1=new MyPoint(0,0);
        MyPoint point2=new MyPoint(10,30.5);
        
        System.out.println("The distance of (0,0) and (10,30.5) is " + point1.distance(point2));
    }
    
}
