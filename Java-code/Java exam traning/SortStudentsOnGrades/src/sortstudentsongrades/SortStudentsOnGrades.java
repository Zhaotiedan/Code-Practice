
package sortstudentsongrades;

import java.util.Arrays;
public class SortStudentsOnGrades {

    public static void main(String[] args) {
        char[][] answers={
            {'A','B','A','C','C','D','E','E','A','D'},
            {'D','B','A','B','C','A','E','E','A','D'},
            {'E','D','D','A','C','B','E','E','A','D'},
            {'C','B','A','E','D','C','E','E','A','D'},
            {'A','B','D','C','C','D','E','E','A','D'},
            {'B','B','E','C','C','D','E','E','A','D'},
            {'B','B','A','C','C','D','E','E','A','D'},
            {'E','B','E','C','C','D','E','E','A','D'}};
        char [] keys={'D','B','D','C','C','D','A','E','A','D'};
        int []count=new int[8];
        for(int row=0;row<answers.length;row++){
            int correctcount=0;
            for(int col=0;col<answers[row].length;col++){
                if(answers[row][col]==keys[col]){
                    correctcount++;
                }
            }
            count[row]=correctcount;
        }
        Arrays.sort(count);
        for(int k=0;k<count.length;k++){
            System.out.println("Student " + k + " 's correct count is " + count[k]);  
        }
    }
    
}
