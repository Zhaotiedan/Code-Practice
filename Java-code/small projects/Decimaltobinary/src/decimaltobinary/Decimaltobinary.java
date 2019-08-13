//十进制转二进制
package decimaltobinary;

import java.util.Scanner;
public class Decimaltobinary {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a decimal number:");
        int decimal = input.nextInt();
        String a="";
        while(decimal!=0){
            a=decimal%2+a;
            decimal=decimal/2;
        }
        System.out.println("The number is" + a);
    }
    
}
