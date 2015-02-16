package com.glacier.consumers;

/**
 * Created by IntelliJ IDEA on 2015-02-16 18:46.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */


import com.glacier.pojos.BaoZi;
import com.glacier.pojos.Basket;

/**
 * 消费者线程类
 */
public class Consumer extends Thread {

    public Consumer(String consumer_name, Basket basket) {
        this.consumer_name = consumer_name;
        this.basket = basket;
    }

    private String consumer_name;
    private Basket basket;

    public BaoZi getOne() {
        return this.basket.getOne();
    }

    @Override
    public void run() {
        while(true) {
            BaoZi baoZi = this.getOne();  //拿到一个包子
            System.out.println( this.consumer_name + " - 吃掉了一个包子 【" + baoZi.getIndex() + " 】篮子里还有【" + this.basket.baoZiList.size() + "】个");

            try {
                Thread.sleep(500);     //吃完一个包子后休息2s
            }catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
