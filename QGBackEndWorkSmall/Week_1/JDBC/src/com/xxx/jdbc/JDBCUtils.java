package com.xxx.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCUtils {

    //内部封装1：这个是进行JDBC连接的
    private Connection getConnection(String url, String username, String password) throws Exception {
        return DriverManager.getConnection(url, username, password);
    }

    //封装1：这个是进行dml操作的，将封装1包含
    public void executeDML(String sql, String url, String username, String password) {
        try  {
            //1进行连接，同时定义conn接受函数的返回值。
            Connection conn = getConnection(url, username, password);
            //2获取执行sql的对象Statement
            Statement stmt = conn.createStatement();
            // 3开启事务
            conn.setAutoCommit(false);

            // 4执行 SQL，返回受影响的行数
            int count = stmt.executeUpdate(sql);

            //5 处理结果
            System.out.println(count);
            if (count > 0) {
                System.out.println("修改成功");
            }

            // 6提交事务
            conn.commit();

        } catch (Exception e) {
            // 回滚事务
            System.out.println("修改失败");
            System.out.println("事务回滚");
            e.printStackTrace();
        }
    }

    // 封装2：执行 DDL 操作
    public void executeDDL(String sql, String url, String username, String password) {
        try  {
            //1进行连接，同时定义conn接受函数的返回值。
            Connection conn = getConnection(url, username, password);
            //2获取执行sql的对象Statement
            Statement stmt = conn.createStatement();
            // 3开启事务
            conn.setAutoCommit(false);

            // 4执行 SQL，返回受影响的行数
            int count = stmt.executeUpdate(sql);

            //少了这部分因为有时候操作成功也会返回0
//            //5 处理结果
//            System.out.println(count);
//            if (count > 0) {
//                System.out.println("修改成功");
//            } else {
//                System.out.println("修改失败");
//            }

            // 6提交事务
            conn.commit();
        } catch (Exception e) {
            // 回滚事务
            System.out.println("事务回滚");
            e.printStackTrace();
        }
    }


   public static void main(String[] args) throws Exception{

            JDBCUtils object = new JDBCUtils();
           //下面4条信息都是自定义的
           String url = "jdbc:mysql://127.0.0.1:3306/db1?useSSL=false";
           String username = "root";
           String password = "12345678";
           String sqlStatement = "update tb_user set money = 1111 where id = 101 ";
           try {
               // 调用 executeDML 方法并传递 SQL 语句、url、username 和 password 作为参数
               object.executeDML(sqlStatement, url, username, password);
           } catch (Exception e) {
               e.printStackTrace();
           }


       }


   }


