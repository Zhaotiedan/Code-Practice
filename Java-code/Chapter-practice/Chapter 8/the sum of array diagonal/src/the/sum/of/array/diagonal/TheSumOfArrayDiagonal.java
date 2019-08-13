
package the.sum.of.array.diagonal;

import java.util.Scanner;
public class TheSumOfArrayDiagonal {
    public static void main(String[] args) {
        double[][] m= getArray();
        System.out.println(" sum of elements in the major diagonal id" + sumMajorDiagonal(m));
    }
    public static double[][] getArray(){
        Scanner input=new Scanner(System.in);
        double [][]m=new double[4][4];
        System.out.println("Enter a 4-by-4 matrix row by row");
        for(int i=0;i<m.length;i++)
            for(int j=0;j<m[0].length;j++)
                m[i][j]=input.nextDouble();
        return m;
    }
    public static double sumMajorDiagonal(double[][]m){
        double sum=0;
        for(int i=0;i<m.length;i++){
            sum+=m[i][i];
        }
        return sum;
    }
}
