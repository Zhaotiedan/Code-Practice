
package findsmallestelement;

import java.util.Scanner;
public class FindSmallestElement {
    public static double min(double[] array){
        double min=array[0];
        for(int i=0;i<array.length;i++){
            if(array[i]<min)
                min=array[i];
        }
        return min;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter ten numbers:");
        double[] array=new double[10];
        for(int i=0;i<array.length;i++){
            array[i]=input.nextDouble();
        }
        double min=min(array);
        System.out.println("The mininum number is:" + min);
    }
    
}
