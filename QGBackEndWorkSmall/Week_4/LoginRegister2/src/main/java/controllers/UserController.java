package controllers;

import models.User;
import services.UserService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/user/*")
public class UserController extends HttpServlet {
    private UserService userService = new UserService();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 处理GET请求，例如显示页面等
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String pathInfo = request.getPathInfo();
        if ("/login".equals(pathInfo)) {
            login(request, response);
        } else if ("/register".equals(pathInfo)) {
            register(request, response);
        } else {
            // 处理其他未知请求
            response.sendError(HttpServletResponse.SC_NOT_FOUND);
        }
    }

    // 处理登录请求
    public void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        User user = userService.login(username, password);
        if (user != null) {
            // 登录成功
            request.getSession().setAttribute("user", user);
            response.sendRedirect(request.getContextPath() + "/home.jsp");
        } else {
            // 登录失败
            response.sendRedirect(request.getContextPath() + "/login.jsp?error=1");
        }
    }

    // 处理注册请求
    public void register(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        // 其他注册信息...

        boolean success = userService.register(username, password);
        if (success) {
            // 注册成功
            response.sendRedirect(request.getContextPath() + "/login.jsp");
        } else {
            // 注册失败
            response.sendRedirect(request.getContextPath() + "/register.jsp?error=1");
        }
    }
}
