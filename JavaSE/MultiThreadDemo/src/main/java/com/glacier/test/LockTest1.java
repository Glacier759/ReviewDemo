package com.glacier.test;

import java.net.SocketPermission;

/**
 * Created by IntelliJ IDEA on 2015-02-16 16:52.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class LockTest1 {

    /**
     * 一般对象锁
     */
    public static void normalSyn() {
        Object object = new Object();

        synchronized (object) {
            System.out.println("object is synchronized!");
        }
    }

    /**
     * 非静态方法锁
     */
    public synchronized void methodSyn() {
        System.out.println("method syn.");
    }

    /**
     * 静态方法锁,相当于锁住LockTest1.class,即当前类的字节码文件
     */
    public synchronized static void staticMethodSyn() {
        System.out.println("static method syn.");
    }

    static class ClassByteSynThread extends Thread {

        public void run() {
            /**
             * 直接锁住类的字节码文件
             */
            synchronized (LockTest1.class) {
                try {
                    Thread.sleep(10000);
                }catch (Exception e) {
                    e.printStackTrace();
                }
                System.out.println("class byte syn.");
            }
        }
    }

    public static void main(String[] args) throws Exception {

        normalSyn();

        LockTest1 obj = new LockTest1();
        obj.methodSyn();

        staticMethodSyn();

        Thread classThread = new ClassByteSynThread();
        classThread.start();

        Thread.sleep(2000);
        //测试在锁住字节码的时候会不会影响别的线程使用这个字节码
        for ( int i = 0; i < 5; i ++ ) {
            //synchronized (LockTest1.class) {
                LockTest1 objTemp = new LockTest1();
                System.out.println("new LockTest1 is successful.");
            //}
        }
    }
}
