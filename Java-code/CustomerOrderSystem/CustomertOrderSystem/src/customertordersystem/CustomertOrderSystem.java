/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package customertordersystem;

import java.util.Scanner;
import java.awt.EventQueue;
import javax.swing.JFrame;    
public class CustomertOrderSystem {

    /**
     * @param args the command line arguments
     */
    //登陆菜单
    public static void loginmenue(){
         System.out.println("1.Manger Login     2.Customer Login   3.LogonNewCount ");
         System.out.println("please enter your login role!");
    }
    //管理员登陆
    public static void MangerLogin(){
        Scanner input=new Scanner(System.in);
        System.out.println("Please enter your user name:");
        String username=input.nextLine();
        System.out.println("Please enter your user passord:");
        String userpassord=input.nextLine();
    }
    //管理员操作菜单
    public static void MangerOperation(){
        Scanner input=new Scanner(System.in);
        System.out.println("1.Check Products   2.Modify Products   3.Delet Products     4.Check Orders    5.Check Staff information");
        int number=input.nextInt();
        boolean quit=true;
        while(quit){
        switch(number){
            case 1:
                CheckProducts();
                break;
            case 2:
                ModifyProducts();
                break;
            case 3:
                DeletProducts();
                break;
            case 4:
                CheckOrders();
                break;
            case 5:
                CheckStaffInformation();
                break;
            default:
                System.out.println("Enter error! please enter again!");
                quit=false;
                break;
            }
        }
    }
    //用户登陆
     public static void CustomerLogin(){
        Scanner input=new Scanner(System.in);
        System.out.println("Please enter your user name:");
        String username=input.nextLine();
        System.out.println("Please enter your user passord:");
        String userpassord=input.nextLine();
    }
     //用户操作
     public static void CustomerOperation(){
         Scanner input=new Scanner(System.in);
        System.out.println("1.Check Products   2.CheckOrders  ");
        int number=input.nextInt();
        boolean quit=true;
        while(quit){
        switch(number){
            case 1:
                CheckProducts();
                break;
            case 2:
                CheckOrders();
                break;
            default:
                System.out.println("Enter error! please enter again!");
                quit=false;
                break;
            }
        }
     }
     //用户注册
    public static void  LogonNewCount(){
       Scanner input=new Scanner(System.in);
        System.out.println("Please enter your newuser name:");
        String username=input.nextLine(); 
        if(Judge()==false){
        System.out.println("Please enter your newuser passord:");
        //将该条记录添加到数据库的登陆表
        
    }
    //判断数据库是否存在该用户
    public static boolean Judge(){
        
    }
    public static void CheckProducts(){
        
    }
    public static void ModifyProducts(){
        
    }
    public static void DeletProducts(){
        
    }
    public static void CheckOrders(){
        
    }
    public static void CheckStaffInformation(){
        
    }
    public static void main(String[] args) {
        // TODO code application logic here
        EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				 LoginFrame frame=new LoginFrame();
			    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			    frame.setVisible(true);		
			}
		});
    }
}
       //loginmenue();
       /*Scanner input=new Scanner(System.in);
       int number=input.nextInt();
       boolean quit=true;
       while(quit){
       switch (number){
           case 1:MangerLogin();
           MangerOperation();
           break;
           case 2: CustomerLogin();
           CustomerOperation();
           break;
           case 3:LogonNewCount();
           break;
           default:
            System.out.println("Enter error! please enter again!");
            quit=false;
            break;
       }       
       
 
    }*/
