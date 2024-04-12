<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Home</title>
</head>
<body>
<h2>欢迎, <%=(request.getSession().getAttribute("user") != null ? ((models.User)request.getSession().getAttribute("user")).getUsername() : "您好")%>!</h2>
<p>你登录成功了.</p>
<!-- 这里可以写其他页面内容 -->
</body>
</html>
