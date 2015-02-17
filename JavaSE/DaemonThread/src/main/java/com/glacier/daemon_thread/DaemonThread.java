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
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * 守护线程
 */
public class DaemonThread implements Runnable {

    public static Logger logger = Logger.getLogger(DaemonThread.class);

    private List<ThreadGroup> thread_group_list = null;

    private Basket basket;
    public DaemonThread( Basket basket) {
        this.thread_group_list = new ArrayList<ThreadGroup>();
        this.basket = basket;
    }

    public void add(ThreadGroup threadGroup) {
        this.thread_group_list.add(threadGroup);
    }

    @Override
    public void run() {
        while (true) {

            if ( Producer.producer_all_number >= Producer.max_producer_all_number_one_day && basket.getRemainBaoziNumber() == 0 ) {
                logger.info("今天包子做够了卖完了,想吃的明儿再来,本店打烊了！！！");
                break;
            }

            for ( ThreadGroup threadGroup:this.thread_group_list ) {
                logger.warn("当前拥有的 " + threadGroup.getName() + " 数量为 -- " + threadGroup.activeCount());
                logger.info("目前卖包子的已经生产了（" + Producer.producer_all_number+"）个包子, 吃包子的已经消费了（" + Consumer.consumer_all_number + "）个包子");

                //剩余多少个包子很关键,不能出现负数情况,所以要加锁取篮子中的数量
                logger.warn("当前篮子里还有 [" + basket.getRemainBaoziNumber() + "] 个包子");
            }
            try {
                Thread.sleep(2000);
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }
}
