package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-02-16 17:27.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */

/**
 * 死锁举例
 */
public class DeadLockDemo extends Thread {

    //这两个对象是要竞争的资源对象
    /*局部变量  每次new DeadLockDemo就是新的对象  那么就不存在两个DeadLockDemo争抢资源问题*/
//    public Object object1 = new Object();
//    public Object object2 = new Object();
    public static Object object1 = new Object();
    public static Object object2 = new Object();

    private int threadNumber;
    private String threadName;

    public String getThreadName() {
        return threadName;
    }

    public void setThreadName(String threadName) {
        this.threadName = threadName;
    }

    public int getThreadNumber() {
        return threadNumber;
    }

    public void setThreadNumber(int threadNumber) {
        this.threadNumber = threadNumber;
    }

    public DeadLockDemo( int threadNumber, String threadName ) {
        this.threadNumber = threadNumber;
        this.threadName = threadName;
    }

    public void run() {
        if ( this.threadNumber % 2 == 0 ) {     //这样的序号线程先拿object1的锁，再拿object2的锁
            synchronized (object1) {
                System.out.println( this.getThreadName() + " - 拿到了 object1. 即将去拿object2.");
                try {
                    Thread.sleep(2000);
                }catch (Exception e) {
                    e.printStackTrace();
                }
                synchronized (object2) {
                    System.out.println( this.getThreadName() + " - 拿到了 object2.");
                }
            }
        } else {
            synchronized (object2) {
                System.out.println( this.getThreadName() + " - 拿到了 object2. 即将去拿object1.");
                try {
                    Thread.sleep(2000);
                }catch (Exception e) {
                    e.printStackTrace();
                }
                synchronized (object1) {
                    System.out.println( this.getThreadName() + " - 拿到了 object1.");
                }
            }
        }
    }

    public static void main(String[] args) {
        DeadLockDemo obj1 = new DeadLockDemo(1, "对象A");
        DeadLockDemo obj2 = new DeadLockDemo(2, "对象B");

        obj1.start();
        obj2.start();
    }
}
