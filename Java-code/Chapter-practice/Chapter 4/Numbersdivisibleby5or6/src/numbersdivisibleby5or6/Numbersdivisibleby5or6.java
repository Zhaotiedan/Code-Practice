
package numbersdivisibleby5or6;

import java.util.Scanner;
public class Numbersdivisibleby5or6 {
    public static void main(String[] args) {
        final int NUMBER_OF_PRIMES_PER_LINE=10;
        int number=0;
        int count=0;
        for(number=100;number<=200;number++){
            if(number%5==0){
                if(number%6!=0){
                    count++;
                    if(count%NUMBER_OF_PRIMES_PER_LINE==0){
                        System.out.println(number);
                    }
                    else System.out.print(number + " ");
                }
            }
            else if (number%6==0){
                count++;
                if(count%NUMBER_OF_PRIMES_PER_LINE==0){
                        System.out.println(number);
                    }
                    else System.out.print(number + " ");
            }
            
        }
    }
    
}
