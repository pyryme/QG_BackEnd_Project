package com.xxx.jdbc;

import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;


public class CRUD_Utils {
    //核心代码：内部封装1，这个是进行JDBC连接的
    private Connection getConnection(String url, String username, String password) throws Exception {
        return DriverManager.getConnection(url, username, password);
    }


    //明天再来改吧，时间比较晚了
    public int create(String sql, String url, String username, String password, Object... params) {
        try {
            Connection conn = getConnection(url, username, password);
            PreparedStatement pstmt = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            setParameters(pstmt, params);
            int affectedRows = pstmt.executeUpdate();
            if (affectedRows == 0) {
                throw new SQLException("Creating record failed, no rows affected.");
            }
            try {
                ResultSet generatedKeys = pstmt.getGeneratedKeys();
                if (generatedKeys.next()) {
                    return generatedKeys.getInt(1);
                }
            }catch{
                    throw new SQLException("Creating record failed, no ID obtained.");
                }

        } catch (Exception e) {
            e.printStackTrace();
            return -1; // indicate failure
        }
    }

    // Read
    public ResultSet read(String sql, String url, String username, String password, Object... params) {
        try (Connection conn = getConnection(url, username, password);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            setParameters(pstmt, params);
            return pstmt.executeQuery();
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    // Update or Delete
    public int updateOrDelete(String sql, String url, String username, String password, Object... params) {
        try (Connection conn = getConnection(url, username, password);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            setParameters(pstmt, params);
            return pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            return -1; // indicate failure
        }
    }

    private void setParameters(PreparedStatement pstmt, Object... params) throws SQLException {
        for (int i = 0; i < params.length; i++) {
            pstmt.setObject(i + 1, params[i]);
        }
    }
}
