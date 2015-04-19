package com.glacier.test;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Created by IntelliJ IDEA on 2015-04-18 09:20.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class Test {
    public static void main(String[] args) {
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            String[] array = bufferedReader.readLine().split(" ");
            System.out.println(Integer.parseInt(array[0]) + Integer.parseInt(array[1]));
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void start() {
        try {
            System.out.println("input: ");
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

            //T表示有几组数据
            int T = Integer.parseInt(bufferedReader.readLine());
            //存储结果信息
            int count = 0;
            for ( int i = 0; i < T; i ++ ) {    //依此对每组数据进行操作
                int n = Integer.parseInt(bufferedReader.readLine());    //n表示山的个数
                String[] nums_str = (bufferedReader.readLine() + " 0").split(" ");   //表示每座山的高度, 增加重点高度0
                int start_pri = 0;  //表示起始位置0高度与前一次座山的高度

                for ( String num_str : nums_str ) {         //遍历每一座山
                    if ( num_str.length() == 0 ) {     //输入错误处理
                        continue;
                    }
                    int num = Integer.parseInt(num_str);     //将山的高度转化为整型值
                    count += Math.abs(num - start_pri) * 2;     //计算距离并加到count
                    start_pri = num;                        //保存前一坐山的高度，为了下次循环计算
                }
            }
            System.out.println("output: " + count);
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void second() {
        try {
            System.out.println("input: ");
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

            int T = Integer.parseInt(bufferedReader.readLine());    //表示多少组数据
            int count = 0;  //距离结果

            for ( int i = 0; i < T; i ++ ) {
                int n = Integer.parseInt(bufferedReader.readLine());
                String[] nums_str = (bufferedReader.readLine() + " 0").split(" ");   //表示每座山的高度, 增加重点高度0
                int start_pri = 0;  //表示起始位置0高度与前一次座山的高度

                for ( String num_str : nums_str ) {         //遍历每一座山
                    if ( num_str.length() == 0 ) {     //输入错误处理
                        continue;
                    }
                    int num = Integer.parseInt(num_str);     //将山的高度转化为整型值
                    count += Math.abs(num - start_pri) * 2;     //计算距离并加到count
                    start_pri = num;                        //保存前一坐山的高度，为了下次循环计算
                }
            }
            System.out.println("output: " + count);
        }catch (Exception e) {
            e.printStackTrace();
        }
    }
}
