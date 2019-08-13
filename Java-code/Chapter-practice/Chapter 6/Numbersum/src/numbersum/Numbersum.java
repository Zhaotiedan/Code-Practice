
package numbersum;

import java.util.Scanner;
public class Numbersum {
    public static int sumDigits(long n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
}
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        long n=input.nextLong();
        System.out.print("返回"+sumDigits(n));
    }
    
}
