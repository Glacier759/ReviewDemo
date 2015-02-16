package com.glacier.producers;

/**
 * Created by IntelliJ IDEA on 2015-02-16 18:12.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */

import com.glacier.pojos.BaoZi;
import com.glacier.pojos.Basket;

/**
 * 生产者线程类
 */
public class Producer extends Thread {

    public Producer(String producer_name, Basket basket) {
        this.producer_name = producer_name;
        this.basket = basket;
    }

    //生产者的名称
    private String producer_name;
    //生产者包的包子的序号
    private int product_seq = 1;
    //生产的包子将要放入的篮子
    private Basket basket;

    private BaoZi produce() {
        BaoZi baoZi = new BaoZi( producer_name + "_" + product_seq );
        product_seq ++;
        return baoZi;
    }

    public void run() {
        while (true) {
            BaoZi baoZi = this.produce();   //生产了一个包子
            this.basket.addOne(baoZi);      //把包子放到篮子里去
            System.out.println( this.getProducer_name() + " - 生产了一个包子 【 " + baoZi.getIndex() + " 】");

            try {
                //没生产一个包子生产3s
                Thread.sleep(3000);
            }catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public String getProducer_name() {
        return producer_name;
    }

    public void setProducer_name(String producer_name) {
        this.producer_name = producer_name;
    }

    public int getProduct_seq() {
        return product_seq;
    }

    public void setProduct_seq(int product_seq) {
        this.product_seq = product_seq;
    }

    public Basket getBasket() {
        return basket;
    }

    public void setBasket(Basket basket) {
        this.basket = basket;
    }
}
