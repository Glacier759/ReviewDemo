package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-04-18 11:23.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class IncomprehensiveThread {
    static private String name;
    public IncomprehensiveThread(String n) {
        name = n;
    }
    synchronized void a() { maybeBusy();
        System.out.println(name + " - a");}
    static synchronized void b() { maybeBusy();
        System.out.println(name + " - b");}
    static void maybeBusy() {
        try {
            System.out.println(name + " - may");Thread.sleep(1000); }
        catch (InterruptedException e) {}
    }
    public static void main(String[] args) {
        final IncomprehensiveThread x = new IncomprehensiveThread("x");
        final IncomprehensiveThread y = new IncomprehensiveThread("y");
        Runnable runnable = new Runnable() {
            public void run() {

                int option = (int) (Math.random() * 4);
                switch (option) {
                    case 0: x.a(); break;
                    case 1: x.b(); break;
                    case 2: y.a(); break;
                    case 3: y.b(); break;
                } } };
        Thread thread1 = new Thread(runnable);
        Thread thread2 = new Thread(runnable);
        thread1.start();
        thread2.start();
    }
}
