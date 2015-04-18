package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-04-18 10:41.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class Weibo {
    private String content;
    public String getContent() { return content; }
    public void setContent(String d) { content = d; }
    public static void modifyCont(Weibo weibo, String content) {
        weibo = new Weibo();
        weibo.setContent(content);
    }
    public static void main(String[] args) {
        Weibo wb = new Weibo();
        wb.setContent("javacontest");
        Weibo wb2 = new Weibo();
        wb2.setContent("jingkao");
        modifyCont(wb, "sudocn");
        System.out.println(wb.getContent());
        System.out.println(wb2.getContent());
    }
}
