package com.glacier.test;


import java.util.HashSet;
import java.util.Set;

/**
 * Created by IntelliJ IDEA on 2015-04-18 11:42.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class PersonSetDemo {
    void someOperation() {
        Set<Object> set = new HashSet<Object>();
        set.add(new Person("张三", 25));
        set.add(new Person("李四", 32));
        set.add("sdsdsd");
    }
}
