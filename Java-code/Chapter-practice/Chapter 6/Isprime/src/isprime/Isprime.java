
package isprime;

import java.util.Scanner;
public class Isprime {
    public static boolean IsPrime(int number){
        for(int j=2;j<=Math.sqrt(number);j++){
            if(number%j==0)
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        int count=0;
        for(int number=1;number<10000;number+=2){
            if(IsPrime(number)==true)
                count++;
        }
        System.out.print(count+1);
    }
    
}
