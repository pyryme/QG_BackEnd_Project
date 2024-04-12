package dao;



import models.User;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDAO {
    // 模拟数据库连接，这里应该也要拓展
    private Connection conn = null;

    // 登录方法
    public User login(String username, String password) {
        // 实际情况中会查询数据库，但是这里直接模拟了，我后面会补上来
        if ("testName".equals(username) && "123456".equals(password)) {
            return new User(username, password);
        } else {
            return null;
        }
    }

    // 注册方法
    public boolean register(String username, String password) {
        // 实际情况中会将用户信息插入数据库，但是时间比较紧，我在后面会补上来
        return true;
    }
}
