<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Register</title>
</head>
<body>
<h2>注册</h2>
<% if (request.getParameter("error") != null) { %>
<p style="color: red;">注册失败，请重试.</p>
<% } %>
<%--<p>由于没有连接数据库，这里的用户名和密码都是模拟的，分别为testName,123456.</p>--%>
<%--这里是调用user(即UserController那个配置了webservlet的文件)中的register函数的意思--%>
<form action="user/register" method="post">
    用户名: <input type="text" name="username"><br>
    密码: <input type="password" name="password"><br>
    <!-- 其他注册信息 -->
    <input type="submit" value="注册">
</form>
<p>已经有帐号了? <a href="login.jsp">登录</a></p>
</body>
</html>
