
package pointincircle;
import java.util.Scanner;
public class Pointincircle {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter a point with two coordinate");
        double x=input.nextDouble();
        double y=input.nextDouble();
        if((Math.pow(x,2)+Math.pow(y,2))<=100)
                System.out.println("point"+"("+ x +","+ y +")" +"is in the circle");
        else
            System.out.println("point"+"("+ x +","+ y +")" +"is not in the circle");
    }
    
}
