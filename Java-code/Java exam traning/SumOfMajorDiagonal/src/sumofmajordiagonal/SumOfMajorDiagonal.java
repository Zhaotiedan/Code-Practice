
package sumofmajordiagonal;

import java.util.Scanner;
public class SumOfMajorDiagonal {
    public static double sumMajorDiagonal (double[][] m){
        double sum=0;
        for(int row=0;row<m.length;row++){
            for(int col=0;col<m[row].length;col++){
                if(row==col){
                    sum+=m[row][col];
                }
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter a 4-by-4 matrix row by row:");
        double [][] array = new double[4][4];
        for(int row=0;row<array.length;row++){
            for(int col=0;col<array[row].length;col++){
                array[row][col]=input.nextDouble();
            }
        }
        double sum=sumMajorDiagonal(array);
        System.out.println("Sum of the elements in the major diagonal is " + sum);
    }
    
}
