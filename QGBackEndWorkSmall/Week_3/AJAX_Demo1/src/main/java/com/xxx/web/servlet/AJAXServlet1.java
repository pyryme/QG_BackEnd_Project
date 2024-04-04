package com.xxx.web.servlet;

import com.alibaba.fastjson.JSON;
import com.xxx.mapper.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import com.fasterxml.jackson.core.JsonProcessingException;
//import com.fasterxml.jackson.databind.ObjectMapper;


@WebServlet("/AJAXDemo1")
public class AJAXServlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //GET POST处理中文乱码
        //request.setCharacterEncoding("UTF-8");
//        String username = request.getParameter("username");
//        username = new String(username,getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);
        System.out.println("get.....");
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        ///////////////////////////////////
        //接受请求参数
        //String username = request.getParameter("username");


        // 模拟一些数据
        //ObjectMapper dataObject = new ObjectMapper("John", 30, "北京");
        ObjectMapper mapper1 = new ObjectMapper("zhangsan", 11, "北京");
        //ObjectMapper mapper2 = new ObjectMapper("lisi", 22, "上海");

        // 转换数据对象为JSON字符串,这里好像和前端的ajax部分重复了，那一边也有这一步
//        ObjectMapper mapper = new ObjectMapper();
//        String jsonData = mapper.writeValueAsString(dataObject);
        String jsonString1 = JSON.toJSONString(mapper1);
        //String jsonString2 = JSON.toJSONString(mapper2);



        // 将JSON字符串写回到客户端------------这里很繁琐，应该有其他的写法
        PrintWriter out1 = response.getWriter();
        out1.print(jsonString1);
        out1.flush();

//        PrintWriter out2 = response.getWriter();
//        out2.print(jsonString2);
//        out2.flush();

    }
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("post.....");
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        ObjectMapper mapper2 = new ObjectMapper("lisi", 22, "上海");
        String jsonString2 = JSON.toJSONString(mapper2);
        PrintWriter out2 = response.getWriter();
        out2.print(jsonString2);
        out2.flush();
        //this.doGet(request, response);这个虽然方便，但是不是从数据库拿来的数据，是模拟的，所以就好像不能这么写
    }



//
//我把用户的信息写道了ObjectMapper中
//
//    // 示例数据对象类
//    class DataObject {
//        private String name;
//        private int age;
//        private String addr;
//
//        public DataObject(String name, int age, String email) {
//            this.name = name;
//            this.age = age;
//            this.addr = addr;
//        }
//
//        // Getters and setters
//        public String getName() {
//            return name;
//        }
//
//        public void setName(String name) {
//            this.name = name;
//        }
//
//        public int getAge() {
//            return age;
//        }
//
//        public void setAge(int age) {
//            this.age = age;
//        }
//
//        public String getEmail() {
//            return addr;
//        }
//
//        public void setEmail(String email) {
//            this.addr = email;
//        }
    }










