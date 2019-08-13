
package randomcharacter;

import java.util.Scanner;
public class Randomcharacter {
    public static void main(String[] args) {
        char ch=(char)('A'+Math.random()*('Z'-'A'+1));
        System.out.println(ch);
    }
}
