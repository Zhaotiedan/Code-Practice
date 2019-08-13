
package assigngrades;

import java.util.Scanner;
public class AssignGrades {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter the number of students:");
        int number=input.nextInt();
        double scores[]=new double[number];
        System.out.print("Enter " + number + " sores :");
        for(int i=0;i<number;i++){
            scores[i]=input.nextDouble();
        }
        double max=scores[0];
        for(int j=0;j<scores.length;j++){
            if(scores[j]>max)
                max=scores[j];
        }
        for(int k=0;k<scores.length;k++){
            char level;
            if(scores[k]>=max-10){
                level='A';
            }
            else if (scores[k]>=max-20){
                level='B';
            }
            else if (scores[k]>=max-30){
                level='C';
            }
            else if(scores[k]>=max-40){
                level='D';
            }
            else{
                level='F';
            }
            System.out.println("student " + k + " score is " + scores[k] + " and grade is " + level);
        }
    }
    
}
