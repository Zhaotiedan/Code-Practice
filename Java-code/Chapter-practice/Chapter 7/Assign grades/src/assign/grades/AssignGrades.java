/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assign.grades;

import java.util.Scanner;
public class AssignGrades {
    public static void main(String[] args) {
        System.out.print("Enter the number of stdents:");
        Scanner input = new Scanner(System.in);
        int number=input.nextInt();
        System.out.print("Enter " + number + " scores");
        int[] scores=new int[number];
        int best=0;
        for(int i=0;i<scores.length;i++){
            int score=input.nextInt();
            scores[i]=score;
            if(scores[i]>best){
                best=scores[i];
            }
        }
        System.out.println("最高分为 "+ best);
        for(int i=0;i<scores.length;i++){
            char level;
            if(scores[i]>=best-10){
                level='A';
            }
            else if(scores[i]>=best-20){
                level='B';
            }
            else if(scores[i]>=best-30){
                level='C';
            }
            else if(scores[i]>=best-40){
                level='D';
            }
            else {
                level='F';
            }
            System.out.println("Student " + i +"score is " + scores[i] + " and grade is " + level);
        }
        
    }
    
}
