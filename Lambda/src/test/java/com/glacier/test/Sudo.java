package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-04-18 10:40.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class Sudo implements Runnable {
    public static void main(String[] args) throws Exception {
        Thread t = new Thread(new Sudo());
        t.start();
        System.out.print("Started");
        t.join();
        System.out.print("Complete");
    }
    public void run() {
        for (int i = 0; i < 4; i++) {
            System.out.print(i);
        }
    }
}