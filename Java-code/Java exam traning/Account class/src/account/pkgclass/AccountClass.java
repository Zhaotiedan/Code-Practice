
package account.pkgclass;

import java.util.Date;
public class AccountClass {
    private int id=0;
    private double balance=0;
    private double annualInterestRate=0;
    private Date dateCreated;
    public AccountClass(){
        //this.dateCreated=new Date();
    }
    public AccountClass(int id,double balance){
        this.id=id;
        this.balance=balance;
        this.dateCreated=new Date();
    }
    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id=id;
    }
    public double getBalance(){
        return balance;
    }
    public void setBalance(double balance){
        this.balance=balance;
    }
    public double getAnnualInterestRate(){
        return annualInterestRate;
    }
    public void setAnnualInterestRate(double annualInterestRate){
        this.annualInterestRate=annualInterestRate;
    }
    public Date getDateCreated(){
        return dateCreated;
    }
    //返回月利率
    public double getMonthlyInterstRate(){
        return annualInterestRate/12;
    }
    //返回月利息
    public double getMonthlyInterst(){
        return balance*annualInterestRate/12;
    }
    //取钱
    public void withDraw(double MoneyNum){
        this.balance-=MoneyNum;
    }
    //存钱
    public void deposit(double MoneyNum){
        this.balance+=MoneyNum;
    }
    public static void main(String[] args) {
        AccountClass myAccount=new AccountClass (1122,20000);
        myAccount.setAnnualInterestRate(4.5/100);
        myAccount.withDraw(2500);
        myAccount.deposit(3000);
        
        System.out.println("余额" + myAccount.getBalance());
        System.out.println("月利息" + myAccount.getMonthlyInterst());
        System.out.println("开户日期" + myAccount.getDateCreated());
    }
    
}
