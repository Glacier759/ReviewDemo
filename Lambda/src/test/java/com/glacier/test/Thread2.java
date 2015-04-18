package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-04-18 11:05.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class Thread2 implements Runnable {
    public void run() {
        System.out.println("run.");
        throw new RuntimeException("Problem");
    }
    public static void main(String[] args) {
        Thread t = new Thread(new Thread2());
        t.start();
        System.out.println("End of method.");
    }

}
