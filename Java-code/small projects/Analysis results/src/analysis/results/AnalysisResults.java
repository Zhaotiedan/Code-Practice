
package analysis.results;

import java.util.Scanner;
public class AnalysisResults {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter the number of scores");
        int n=input.nextInt();
        double [] scores=new double[n];
        double sum=0;
        System.out.print("Enter the scores:");
        for(int i=0;i<n;i++){
            scores[i]=input.nextDouble();
            if(scores[i]>0&&scores[i]<=100)
            sum+=scores[i];
        }
        double average = sum/n;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(scores[i]>average)
                count1++;
            if(scores[i]<average)
                count2++;
        }
        System.out.println("The average is" + average);
        System.out.println("Number of elments above the average is" + count1);
        System.out.println("Number of elments above the average is" + count2);
    }
    
}
