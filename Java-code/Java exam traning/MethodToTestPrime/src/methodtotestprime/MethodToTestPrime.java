
package methodtotestprime;

public class MethodToTestPrime {
    public static void main(String[] args) {
        int count=0;
        for(int number=2;number<10000;number++){
            if(isPrime(number)){
                count++;
            }
        }
        System.out.println("The number of prime is " + count);
    }
    public static boolean isPrime(int number){
        for(int divisor=2;divisor<=number/2;divisor++){
            if(number%divisor==0){
                return false;
            }
        }
        return true;
    }
    
}
