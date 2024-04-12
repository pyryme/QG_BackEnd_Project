package services;

import dao.UserDAO;
import models.User;

public class UserService {
    private UserDAO userDAO = new UserDAO();

    // 登录逻辑
    public User login(String username, String password) {
        return userDAO.login(username, password);
    }

    // 注册逻辑
    public boolean register(String username, String password) {
        // 可以在这里进行注册逻辑的处理，例如检查用户名是否已存在等
        return userDAO.register(username, password);
    }
}
