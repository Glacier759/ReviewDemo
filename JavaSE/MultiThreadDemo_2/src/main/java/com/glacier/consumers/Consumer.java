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
    //设置最大的可连续等待的次数,一旦超过该值,则消费者退出
    private static int max_sleep_time_continue = 3;
    private int sleep_time_continue_count = 0;
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
            /*******************使用sleep代替wait/notify （需注掉Basket中相关代码）************************/
            /*使用sleep会损失掉一部分性能,但会提升程序的可阅读性降低开发难度*/
            while (baoZi == null) {
                try {
                    if ( sleep_time_continue_count >= max_sleep_time_continue ) {
                        break;
                    }

                    sleep_time_continue_count ++;
                    System.out.println( this.consumer_name + " 要求上包子! 劳资TM等 " + sleep_time_continue_count + " 年了！！" );
                    Thread.sleep(1000);
                }catch (Exception e) {
                    e.printStackTrace();
                }
                baoZi = this.basket.getOne();
            }
            /******************************************************************************************/
            if ( baoZi != null )
                System.out.println( this.consumer_name + " - 吃掉了一个包子 【" + baoZi.getIndex() + " 】篮子里还有【" + this.basket.baoZiList.size() + "】个");
            return baoZi;
        }
    }

    @Override
    public void run() {
        while(true) {
            BaoZi baoZi = this.getOne();  //拿到一个包子
            if ( baoZi == null ) {
                System.out.println("等了 " + max_sleep_time_continue + " 年了还TM不给上包子！？ 不吃了！");
                break;
            }
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
