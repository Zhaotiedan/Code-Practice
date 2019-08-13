
package arrayindex;
import java.util.Scanner;
public class ArrayIndex {
    public static void main(String[] args) {
        int []arr=new int[100];
        for(int i=0;i<arr.length;i++){
            arr[i]=(int)(Math.random()*100);
        }
        System.out.println("输入数组下标：");
        Scanner input=new Scanner (System.in);
        int  i= input.nextInt();
        try{
            System.out.println(arr[i]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Out of Bounds");
        }
    }
    
}
