package com.glacier.controler;

import com.glacier.consumers.Consumer;
import com.glacier.daemon_thread.DaemonThread;
import com.glacier.daemon_thread.DaemonThread4AddElement;
import com.glacier.pojos.Basket;
import com.glacier.producers.Producer;
import org.apache.log4j.Logger;

/**
 * Created by IntelliJ IDEA on 2015-02-16 19:07.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */

/**
 * 1. 周期输出当下有多少个生产者
 * 2. 周期输出当下有多少个消费者
 * 3. 周期加入生产者
 * 4. 周期加入消费者
 * 5. 周期输出一共生产了多少个包子,一共消费了多少个包子
 * 6. 满足一定条件后,饭店一天的营业结束,系统退出
 */
public class SystemControler {

    public static Logger logger = Logger.getLogger(SystemControler.class);

    public static void main(String[] args) {

        ThreadGroup producer_thread_group = new ThreadGroup("生产者线程组");
        ThreadGroup consumer_thread_group = new ThreadGroup("消费者线程组");

        Basket basket = new Basket(1);

        Producer producer1 = new Producer("包子师傅王大壮", basket, producer_thread_group);
        Producer producer2 = new Producer("包子师傅李不胖", basket, producer_thread_group);
        Producer producer3 = new Producer("包子师傅韩梅梅", basket, producer_thread_group);
        Producer producer4 = new Producer("包子师傅李雷雷", basket, producer_thread_group);
        Consumer consumer1 = new Consumer("大爷李刚", basket, consumer_thread_group);
        Consumer consumer2 = new Consumer("大娘王婆", basket, consumer_thread_group);

        producer1.start();
        //producer2.start();
        producer3.start();
        producer4.start();
        consumer1.start();
        consumer2.start();

        /**
         * 启动守护线程
         */
        DaemonThread daemon_thread = new DaemonThread(basket);
        daemon_thread.add(producer_thread_group);
        daemon_thread.add(consumer_thread_group);
        new Thread(daemon_thread).start();

        /**
         * 启动添加元素的守护线程
         */
        DaemonThread4AddElement daemon_thread_4_add_element = new DaemonThread4AddElement(producer_thread_group, consumer_thread_group, basket);
        new Thread(daemon_thread_4_add_element).start();

    }
}
