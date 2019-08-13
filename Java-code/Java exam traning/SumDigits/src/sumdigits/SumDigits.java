
package sumdigits;

import java.util.Scanner;
public class SumDigits {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter a number:");
        int number=input.nextInt();
        int sum=sumDigits(number);
        System.out.println("The sumdigits of number " + number + " is " + sum);
        
    }
    public static int sumDigits(long n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
}
