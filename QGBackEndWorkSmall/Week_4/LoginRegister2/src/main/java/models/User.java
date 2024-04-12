package models;

public class User {
    private String username;
    private String password;

    public User() {
        // 默认构造函数
    }

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    // Getter和Setter方法，这里没有用到，后面连上数据库了再来补充和调用
    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
