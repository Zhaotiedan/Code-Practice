
package triangle;

import java.util.Scanner;
public class Triangle extends GeometricObject{
    private double side1=1.0;
    private double side2=1.0;
    private double side3=1.0;
    public Triangle(){
        
    }
    public Triangle(double side1,double side2,double side3,String color,boolean filled){
        super(color,filled);
        this.side1=side1;
        this.side2=side2;
        this.side3=side3;
    }
    public double getSide1(){
        return side1;
    }
    public double getSide2(){
        return side2;
    }
    public double getSide3(){
        return side3;
    }
    public double getArea(){
        double s = side1+side2+side3;
        return Math.sqrt( s*(s-side1)*(s-side2)*(s-side3));
    }
    public double getPerimeter(){
        return side1+side2+side3;
    }
    public String toString(){
        return "Triangle side1= " + side1 + " side2= " + side2 +" side3= " + side3;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Please enter the three side of the triangle:");
        double side1=input.nextDouble();
        double side2=input.nextDouble();
        double side3=input.nextDouble();
        System.out.println("Please enter the color of the triangle:");
        String color=input.next();//不能在next后面加String
        System.out.println("Please enter the isfilled of the triangle:");
        boolean filled=input.nextBoolean();
        
        Triangle mytriangle=new Triangle(side1,side2,side3,color,filled);
        System.out.println("The area is " +mytriangle.getArea() );
        System.out.println("The Perimeter is " +mytriangle.getPerimeter());
        System.out.println("The Color is " +mytriangle.getColor() );
        System.out.println("if filled " +mytriangle.isFilled() );
    }
    
}
