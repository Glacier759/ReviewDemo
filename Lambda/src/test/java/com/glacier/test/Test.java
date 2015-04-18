package com.glacier.test;

import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * Created by IntelliJ IDEA on 2015-04-18 09:20.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class Test {

    public static void main(String[] args) {
        int[] da1 = new int[]{1, 3, 5};
        int[] da2 = new int[]{2, 4, 6};
        System.out.print(da2[da1[0]]);
        interchange(da1, da2);
        System.out.print(da1[da2[0]]);
    }
    static void interchange(int[] da1, int[] da2) {
        int[] dat = (int[]) da1.clone();
        da1 = (int[]) da2.clone();
        da2 = (int[]) dat.clone();
    }

}
