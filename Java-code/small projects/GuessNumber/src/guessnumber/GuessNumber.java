
package guessnumber;

import java.util.Scanner;
public class GuessNumber {
    public static void main(String[] args) {
        int number=(int)(Math.random()*101);
        Scanner input=new Scanner(System.in);
        System.out.println("Guess a magic number between 0 and 100");
        int guess =-1;
        while(guess!=number){
            System.out.print("\nEnter your guess");
            guess = input.nextInt();
            
            if(guess==number)
                System.out.println("Yes,the number is" + number);
            else if(guess>number)
                System.out.println("Your guess is too high");
            else if(guess<number)
                System.out.println("Your guess is too low");
        }
    }
    
}
