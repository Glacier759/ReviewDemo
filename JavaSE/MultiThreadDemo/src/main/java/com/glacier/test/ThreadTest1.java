package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-02-16 16:25.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class ThreadTest1 extends Thread {

    public void run() {
        try {
            Thread.sleep(1000);
        }catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("this thread is running ... ");
    }

    public static void main(String[] args) {
        Thread thread = new ThreadTest1();
        thread.start();

        System.out.println("main thread is end !");
    }
}
