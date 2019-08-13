/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package minutes;

import java . util .Scanner;
public class Minutes { 
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of minutes:");
        int minutes = input.nextInt();
        
        int years = minutes / 525600;
        int days = minutes / 1440;
        System.out.println(minutes + "minutes" + "is approximately" + years + "years" + days + "days");
    }
    
}
