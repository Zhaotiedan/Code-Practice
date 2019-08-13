

package dividedby5or6;
public class DividedBy5or6 {
    public static void main(String[] args) {
        final int NUMBER_OF_NUMBERS_PER_LINE=10;
        int count=0;
        int number=0;

        for(number=100;number<=200;number++){
            boolean IsNumber=false;
            if((number%5==0)&&(number%6!=0)){
                IsNumber=true;
            }
            else if((number%6==0)&&(number%5!=0)){
                IsNumber=true;
            }
            
            if(IsNumber){
                count++;
                if(count%NUMBER_OF_NUMBERS_PER_LINE==0){
                System.out.println();
            }
            else{
                System.out.print(number + " ");
            }
            }
        }
    }
    
}
