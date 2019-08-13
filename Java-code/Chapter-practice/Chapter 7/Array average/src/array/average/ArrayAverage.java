/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package array.average;

import java.util.Scanner;
public class ArrayAverage {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter 10 int values");
        int [] array1=new int[10];
        for(int i=0;i<array1.length;i++){
            array1[i]=input.nextInt();
        }
        double a=average(array1);
        System.out.println("Average is"+ a);
        
        System.out.print("Enter 10 duble values");
        double[] array2=new double[10];
        for(int j=0;j<array1.length;j++){
            array2[j]=input.nextDouble();
        }
        double b=average(array2);
        System.out.println("Average is"+ b);
        
    }
    public static int average(int[] array){
        double sum=0;
        for(int i=0;i<array.length;i++){
            sum+=array[i];
        }
        return (int)(sum/array.length*10+0.5)/10;
    }
    public static double average(double[] array){
        double sum=0;
        for(int j=0;j<array.length;j++){
            sum+=array[j];
        }
        return (sum/array.length*10+0.5)/10;
    }
    
}
