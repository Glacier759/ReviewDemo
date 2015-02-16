package com.glacier.pojos;

/**
 * Created by IntelliJ IDEA on 2015-02-16 18:11.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */

/**
 * 包子的封装类
 */
public class BaoZi {
    //编号，标识包子的唯一性
    private String index;

    public String getIndex() {
        return index;
    }

    public void setIndex(String index) {
        this.index = index;
    }

    public BaoZi(String index) {
        this.index = index;
    }
}
