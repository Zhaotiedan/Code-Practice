
package myinteger;
public class MyInteger {
    int value;
    static int MAX_VALUE;
    static int MIN_VALUE;
    public MyInteger(int value){
        this.value=value;
    }
    public int getValue(){
        return value;
    }
    public boolean isEven(){
        if(value%2==0)
            return true;
        else
            return false;
    }
    public boolean isOdd(){
        if(value%2==0)
            return false;
        else
            return true;
    }
    public boolean isPrime(){
        for(int i=2;i<value/2;i++){
            if(value%i==0)
                return false;
        }
        return true;
    }
    public static boolean isEven(int value){
        if(value%2==0)
            return true;
        else
            return false;
    }
    public static boolean isOdd(int value){
        if(value%2==0)
            return false;
        else
            return true;
    }
    public static boolean isPrime(int value){
        for(int i=2;i<value/2;i++){
            if(value%i==0)
                return false;
        }
        return true;
    }
     public static boolean isEven(MyInteger value){
        if(value.getValue()%2==0)
            return true;
        else
            return false;
    }
    public static boolean isOdd(MyInteger value){
        if(value.getValue()%2==0)
            return false;
        else
            return true;
    }
    public static boolean isPrime(MyInteger value){
        for(int i=2;i<value.getValue()/2;i++){
            if(value.getValue()%i==0)
                return false;
        }
        return true;
    }
    public boolean equal(int value){
        return true;
    }
    public boolean equal(MyInteger value){
        return (this.value==value.getValue());
    }
    public static int parseInt(char array[]){
        return Integer.valueOf(new String(array));
    }
    public static int parseInt(String s){
        return Integer.valueOf(s);
    }
    public static void main(String[] args) {
        String s="1234";
        char arr[]={'1','2','3','4'};
        MyInteger value1=new MyInteger(10);
        MyInteger value2=new MyInteger(7);
        System.out.println(value1.isEven(value1));
        System.out.println(value1.isOdd(value1));
        System.out.println(value1.isPrime(value1));
        System.out.println(value2.isEven(value2));
        System.out.println(value2.isOdd(value2));
        System.out.println(value2.isPrime(value2));
        System.out.println("value1 and value equal? " + value1.equals(value2));
        System.out.println("arr to an int value: " + value1.parseInt(arr));
        System.out.println("string to a int value " + value1.parseInt(s));
    }
}
