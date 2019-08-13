
package triangle;

import java.util.Scanner;
public class Triangle {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter three edges");
        double a=input.nextDouble();
        double b=input.nextDouble();
        double c=input.nextDouble();
        if(a+b>c&&a+c>b&&c+b>a)
            System.out.println("can edges" + a + b +"and"+ c +"from a triangle?"+ true);
        else
            System.out.println("can edges" + a + b +"and"+ c +"from a triangle?"+ false);
    }
    
}
