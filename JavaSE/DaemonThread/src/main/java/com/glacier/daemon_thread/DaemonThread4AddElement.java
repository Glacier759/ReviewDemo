package com.glacier.daemon_thread;

/**
 * Created by IntelliJ IDEA on 2015-02-17 14:12.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */

import com.glacier.consumers.Consumer;
import com.glacier.pojos.Basket;
import com.glacier.producers.Producer;
import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.List;

/**
 * 守护线程,为了增强模拟的真实性,周期性的向系统中添加生产者或者消费者
 */
public class DaemonThread4AddElement implements Runnable {

    public static Logger logger = Logger.getLogger(DaemonThread4AddElement.class);

    private ThreadGroup producer_thread_group;
    private ThreadGroup consumer_thread_group;
    private Basket basket;

    public DaemonThread4AddElement( ThreadGroup producer_thread_group, ThreadGroup consumer_thread_group, Basket basket ) {
        this.producer_thread_group = producer_thread_group;
        this.consumer_thread_group = consumer_thread_group;
        this.basket = basket;
    }

    @Override
    public void run() {
        int producer_new_count = 0, consumer_new_count = 0;
        while (true) {

            if ( Producer.producer_all_number >= Producer.max_producer_all_number_one_day && basket.getRemainBaoziNumber() == 0 ) {
                logger.info("今天包子做够了卖完了,想吃的明儿再来,本店打烊了！！！");
                break;
            }

            if ( producer_thread_group.activeCount() < consumer_thread_group.activeCount() ) {
                producer_new_count++;
                Producer producer_one = new Producer("新增生产者【" + producer_new_count + "】", basket, producer_thread_group);
                logger.warn(producer_one.getProducer_name() + " 应聘上班,直接开始蒸包子！");
                producer_one.start();
            }
            else {
                consumer_new_count ++;
                Consumer consumer_one = new Consumer("刚来的消费者【" + consumer_new_count + "】", basket, consumer_thread_group);
                logger.warn(consumer_one.getConsumer_name() + " 进店吃包子啦！");
                consumer_one.start();
            }
            try {
                Thread.sleep(2000);
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }
}
