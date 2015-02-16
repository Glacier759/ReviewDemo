package com.glacier.controler;

import com.glacier.consumers.Consumer;
import com.glacier.pojos.Basket;
import com.glacier.producers.Producer;

/**
 * Created by IntelliJ IDEA on 2015-02-16 19:07.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class SystemControler {
    public static void main(String[] args) {
        Basket basket = new Basket(1);

//        Producer producer = new Producer("包子师傅王大壮", basket);
//        Consumer consumer = new Consumer("吃包子大爷李刚", basket);
//
//        producer.start();
//        consumer.start();

        Producer producer1 = new Producer("包子师傅王大壮", basket);
        Producer producer2 = new Producer("包子师傅李不胖", basket);
        Consumer consumer = new Consumer("吃包子大爷李刚", basket);

        producer1.start();
        producer2.start();
        consumer.start();
    }
}
