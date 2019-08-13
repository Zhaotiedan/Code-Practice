/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package studentmanage;

import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author Administrator
 */
public class StudentManage {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here


        ArrayList<Student> array = new ArrayList<Student>();

        while(true) {   //停止的另一种方式，设置标志位flag = true  while(flag)
            System.out.println("-------------------欢迎来到学生管理系统------------------------");
            System.out.println("------              1. 查看所有学生                      -----");
            System.out.println("------              2. 添加学生                          -----");
            System.out.println("------              3. 删除学生                          -----");
            System.out.println("------              4. 修改学生                          -----");
            System.out.println("------              5. 退出                              -----");
            System.out.println("--------------------------------------------------------------");
            System.out.print("请输入您的选择：");
            Scanner sc = new Scanner(System.in);
            String choice = sc.nextLine();
            switch (choice) {
                case "1":
                    //查看所有学生
                    findAllStudent(array);
                    System.out.println();
                    break;
                case "2":
                    //添加学生
                    addStudent(array);
                    System.out.println();
                    break;
                case "3":
                    deleteStudent(array);
                    System.out.println();
                    break;
                case "4":
                    updateStudent(array);
                    System.out.println();
                    break;
                case "5":

                default:
                    // System.out.println("------              5. 退出                              -----");
                    System.out.println("                     感谢您的使用                               ");
                    //flag = false;
                    System.exit(0);
                    break;
            }
        }
    }

    //查看所有学生
    public static void findAllStudent(ArrayList<Student> array){
        if(array.size() == 0){
            System.out.println("无学生信息，请重新选择");
            return;
        }
        System.out.println();
        System.out.println("学号\t\t\t\t姓名\t\t\t\t年龄\t\t\t\t居住地");
        System.out.println("-------------------------------------------------------------------------");
        for(int x = 0; x < array.size(); x++)
        {
            Student s = array.get(x);
            System.out.println(s.getId()+"\t\t\t\t" + s.getName() + "\t\t\t\t" + s.getAge() + "\t\t\t\t" + s.getAddress());
        }
        System.out.println("-------------------------------------------------------------------------");
    }

    //添加学生
    public static void addStudent(ArrayList<Student> array)
    {
        Scanner in = new Scanner(System.in);
        String id ="";

        while(true) {
            System.out.print("输入学号：");
            id = in.nextLine();
            int x;
            boolean flag = false;
            for(x = 0; x < array.size(); x++ )
            {
                Student s = array.get(x);
                if(id.equals(s.getId())) {
                    flag = true;
                    break;
                }
            }
            if(flag){
                System.out.println("学号被占用，请重新输入");
            }
            else{
                break;
            }

        }
        System.out.print("输入姓名：");
        String name = in.nextLine();
        System.out.print("输入年龄：");
        String age = in.nextLine();
        System.out.print("输入地址：");
        String address = in.nextLine();

        //创建学生对象
        Student s = new Student(id,name,age,address);
        /*
        Student s = new Student();
        s.setId(id);
        s.setName(name);
        s.setAge(age);
        s.setAddress(address);
        */
        array.add(s);
        System.out.println("添加学生成功");
    }

    //删除学生
    public static void deleteStudent(ArrayList<Student> array){
        //思路：根据学号删除。先遍历学生列表查看学生是否存在
        Scanner in = new Scanner(System.in);
        System.out.print("输入要删除学生的学号：");
        String id = in.nextLine();

        int index = -1;
        for(int x = 0; x < array.size(); x++){
            Student s = array.get(x);
            if(id.equals(s.getId())){
                index = x;
                break;
            }
        }
        if(index == -1){
            System.out.print("该学生信息不存在，是否继续当前删除操作（Yes or No):");
            String choice = in.nextLine();
            if(choice.equalsIgnoreCase("Yes")){
                deleteStudent(array);
            }else if(choice.equalsIgnoreCase("No"))
            {
                return;
            }
            else{
                System.out.println("输入信息有误，返回主界面");
                return;
            }
        }else
        {
            array.remove(index);
            System.out.println("删除学生成功");
        }

    }

    //修改学生信息
    public static void updateStudent(ArrayList<Student> array){
        //输入学号查找学生是否存在
        Scanner in = new Scanner(System.in);
        System.out.print("输入要更新学生的学号：");
        String id = in.nextLine();

        int index = -1;
        for(int x = 0; x < array.size(); x++){
            Student s = array.get(x);
            if(id.equals(s.getId())){
                index = x;
                break;
            }
        }
        if(index == -1){
            System.out.print("该学生信息不存在，是否继续当前更新操作（Yes or No):");
            String choice = in.nextLine();
            if(choice.equalsIgnoreCase("Yes")){
                updateStudent(array);
            }else if(choice.equalsIgnoreCase("No"))
            {
                return;
            }
            else{
                System.out.println("输入信息有误，返回主界面");
                return;
            }
        }else
        {
            Student s = array.get(index);
            boolean flag = true;
            System.out.println("-----选择更新学生信息选项------");
            System.out.println("--      1. 姓名         --");
            System.out.println("--      2. 年龄         --");
            System.out.println("--      3. 地址         --");
            System.out.println("--      4. 返回主界面    --");
            System.out.println("--------------------------");
            while(flag) {
                System.out.print("请输入您的选择：");
                Scanner sc = new Scanner(System.in);
                String choice = sc.nextLine();
                switch (choice) {
                    case "1":
                        System.out.print("输入修改姓名：");
                        String name = in.nextLine();
                        s.setName(name);
                        System.out.print("继续更新操作（Yes or No):");
                        String a = in.nextLine();
                        if(a.equalsIgnoreCase("Yes"))
                            break;
                        else if(a.equalsIgnoreCase("No")){
                            array.set(index,s);
                            System.out.println("更新操作完成，返回主界面");
                            return;
                        }
                        else{
                            System.out.println("输入信息有误，返回主界面");
                            return;
                        }
                    case "2":
                        System.out.print("输入修改年龄：");
                        String age = in.nextLine();
                        s.setAge(age);
                        System.out.print("继续更新操作（Yes or No):");
                        String b = in.nextLine();
                        if(b.equalsIgnoreCase("Yes"))
                            break;
                        else if(b.equalsIgnoreCase("No")){
                            array.set(index,s);
                            System.out.println("更新操作完成，返回主界面");
                            return;
                        }
                        else{
                            System.out.println("输入信息有误，返回主界面");
                            return;
                        }

                    case "3":
                        System.out.print("输入修改地址：");
                        String address = in.nextLine();
                        s.setAddress(address);
                        System.out.print("继续更新操作（Yes or No):");
                        String c = in.nextLine();
                        if(c.equalsIgnoreCase("Yes"))
                            break;
                        else if(c.equalsIgnoreCase("No")){
                            array.set(index,s);
                            System.out.println("更新操作完成，返回主界面");
                            return;
                        }
                        else{
                            System.out.println("输入信息有误，返回主界面");
                            return;
                    }
                    case "4":
                        array.set(index,s);
                        System.out.println("修改信息完成。");
                        return;
                    default:
                        System.out.println("输入信息有误。返回主界面");
                        return;
                }
            }
        }
    }
}

