package com.glacier.pojos;

/**
 * Created by IntelliJ IDEA on 2015-02-16 18:21.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */

import java.util.LinkedList;

/**
 * 包子的容器对象，负责包子的放入和拿出
 */
public class Basket  {

    public Basket(int index) {
        this.index = index;
        this.baoZiList = new LinkedList<BaoZi>();
    }

    private int index;
    public LinkedList<BaoZi> baoZiList;

    public void addOne(BaoZi baoZi) {
        synchronized (this) {
            this.baoZiList.add(baoZi);
            this.notifyAll();           //如果有人给篮子里放了包子，激活所有线程
        }
    }

    public BaoZi getOne() {
        synchronized (this) {           //保证一个篮子只有一个线程在操作
            BaoZi baoZi = this.baoZiList.pollFirst();
            while ( baoZi == null ) {   //循环保证一致尝试在篮子里取包子
                System.out.println("老板上包子！");
                try {
                    this.wait();        //如果篮子里没有包子  则当前线程wait
                    baoZi = this.baoZiList.pollFirst();     //线程被激活后，再从篮子中取包子
                }catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return baoZi;
        }
    }
}
