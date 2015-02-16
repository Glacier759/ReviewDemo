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
    public static int max_consumer_number = 3;
    private int count = 0;
    public Consumer(String consumer_name, Basket basket) {
        this.consumer_name = consumer_name;
        this.basket = basket;
    }

    private String consumer_name;
    private Basket basket;

    public BaoZi getOne() {
        synchronized (Consumer.class) {
            BaoZi baoZi = this.basket.getOne();
            System.out.println( this.consumer_name + " - 吃掉了一个包子 【" + baoZi.getIndex() + " 】篮子里还有【" + this.basket.baoZiList.size() + "】个");
            return baoZi;
        }
    }

    @Override
    public void run() {
        while(true) {
            BaoZi baoZi = this.getOne();  //拿到一个包子

            try {
                this.count ++;
                if ( this.count == this.max_consumer_number ) {
                    System.out.println( this.consumer_name + " - 今天吃了 " + this.max_consumer_number + " 个包子,吃饱了遛弯儿去~" );
                    break;
                }
                Thread.sleep(500);     //吃完一个包子后休息2s
            }catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
