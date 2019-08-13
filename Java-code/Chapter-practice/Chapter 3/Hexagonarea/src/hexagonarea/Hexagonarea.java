
package hexagonarea;

import java.util.Scanner;
public class Hexagonarea {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the side");
        double s = input.nextDouble();
        double area = 6*Math.pow(s,2)/4/Math.tan(Math.PI/6);
        System.out.println("The area of the hexgon is" + area);
    }
}
