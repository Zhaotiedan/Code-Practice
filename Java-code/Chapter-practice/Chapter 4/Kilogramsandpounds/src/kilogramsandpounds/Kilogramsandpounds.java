
package kilogramsandpounds;

import java.util.Scanner;
public class Kilogramsandpounds {
    public static void main(String[] args) {
        System.out.println("千克     磅      磅     千克");
        int i=0;
        for(i=1;i<=100;i++){
            System.out.println(i*2-1+ "       "+(int) (i*2.2*10+0.5)/10.0 + "      " + (i*5+15) +"    " + (int)((i*5+15)/2.2*100+0.5)/100.0 );
        }
    }
    
}
