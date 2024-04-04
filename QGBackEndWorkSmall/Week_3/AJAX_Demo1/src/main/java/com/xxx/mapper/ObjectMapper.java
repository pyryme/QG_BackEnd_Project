package com.xxx.mapper;

public class ObjectMapper {
    private String name;
    private int age;
    private String addr;


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddr() {
        return addr;
    }

    public void setAddr(String addr) {
        this.addr = addr;
    }

    @Override
    public String toString() {
        return "ObjectMapper{" +
                "name='" + name + '\'' +
                ", age='" + age + '\'' +
                ", addr='" + addr + '\'' +
                '}';




    }
    public ObjectMapper(String name, int age, String addr) {
        this.name = name;
        this.age = age;
        this.addr = addr;
    }



}
