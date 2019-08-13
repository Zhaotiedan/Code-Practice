/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package customertordersystem;
import java.sql.*;
/**
 *
 * @author Administrator
 */
public class DataBase {
    private String dbURL;//数据库连接url
    private String user;//数据库的登录名
    private String password;//数据库的登录密码
    private Connection conn;
    private Statement stmt;
    public ResultSet rs;
    public void Connection ()
{
       dbURL="jdbc:odbc:students";// 数据库标识名
       user="sa";// 数据库用户名
       password="123456"; // 数据库用户密码

         try {
           Class.forName("sun.jdbc.odbc.JdbcOdbcDriver"); //加载驱动器
           conn=DriverManager.getConnection(dbURL,user,password); //获取连接
               stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,
          ResultSet.CONCUR_UPDATABLE);
           } catch (Exception e)
           {
               e.printStackTrace();
           }
}
 public boolean isLogin(String strUserID,String strPassword)//传入用户账号，密码
 {
     try
     {
         rs = stmt.executeQuery("select * from UserInfo where UserID='"+strUserID+"' and Password='"+strPassword+"'");
         if (rs.next())//如果rs可以next则说明该用户存在，切密码正确。
         {
             return true;
         }
     }
     catch(Exception e)
     {
         e.printStackTrace();
     }
     return false;
 }

}

