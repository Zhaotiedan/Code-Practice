/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package computevlome;

import java . util . Scanner;

public class ComputeVlome {
    public static void main(String[] args) {
        final double PI = 3.14159;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number for radius:");
        double radius = input.nextDouble();
        System.out.print("Enter a new number for length:");
        double length = input.nextDouble();
        double area = radius * radius * PI;
        double vlome = area * length;
        
        
        System.out.println("The vlome of the circle of radius" + radius +"and length"+ length +"is" + vlome);
    }
    
}
