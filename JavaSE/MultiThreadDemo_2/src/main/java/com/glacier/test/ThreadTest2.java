package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-02-16 16:31.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class ThreadTest2 implements Runnable {

    public static void main(String[] args) {
        Runnable runnable = new ThreadTest2();
        Thread thread = new Thread(runnable);

        thread.start();
        System.out.println("main thread is end!");
    }


    @Override
    public void run() {
        System.out.println("i am runnable.");
    }
}
