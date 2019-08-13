
package arrayaverage;

import java.util.Scanner;
public class ArrayAverage {

    public static int average(int[] array){
        int sum1=0;
        for(int i=0;i<array.length;i++){
            sum1+=array[i];
        }
        return (int)(sum1/array.length);
    }
    public static double average(double[] array){
        double sum2=0;
        for(int j=0;j<array.length;j++){
            sum2+=array[j];
        }
        return sum2/array.length;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter 10 int values:");
        int array1[]=new int[10];
        for(int i=0;i<array1.length;i++){
            array1[i]=input.nextInt();
        }
        System.out.println("Enter 10 double values:");
        double array2[]=new double[10];
        for(int j=0;j<array2.length;j++){
            array2[j]=input.nextDouble();
        }
        System.out.println("The average of the 10 int values is: " + average(array1));
        System.out.println("The average of the 10 double values is: " + average(array2));
    }
    
}
