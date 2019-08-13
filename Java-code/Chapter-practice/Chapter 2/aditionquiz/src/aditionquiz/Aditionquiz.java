/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aditionquiz;

import java .util.Scanner;
    public class Aditionquiz {
    public static void main(String[] args) {
        int number1=(int)(Math.random()*100);
        int number2=(int)(Math.random()*100);
        System.out.print("What is"+ number1 + "+" + number2 + "?");
        Scanner input = new Scanner(System.in);
        int answer = input.nextInt();
        if(number1 + number2 ==answer)
            System.out.println("you are correct!");
        else
            System.out.println("your answer is wrong\n" + number1 + "+" + number2 + "should be"+ (number1 + number2));
    }
    
}
