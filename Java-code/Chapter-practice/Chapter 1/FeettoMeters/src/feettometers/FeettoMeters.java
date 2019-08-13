/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package feettometers;

import java . util . Scanner;
public class FeettoMeters {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a value for feet:");
        double feet = input.nextDouble();
        double meters = 0.305 * feet;
        
        System.out.println(feet + "feet" + "is" + meters + "meters");
    
    }
    
}
