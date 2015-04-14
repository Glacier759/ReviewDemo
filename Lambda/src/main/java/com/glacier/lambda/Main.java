package com.glacier.lambda;

import com.glacier.lambda.pojo.Person;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Created by IntelliJ IDEA on 2015-04-14 20:46.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class Main {

    public static void main(String[] args) {
        Main obj = new Main();
        obj.lambda_001();
        obj.lambda_002();
    }

    public void lambda_001() {
        String[] atp = {"Rafael Nadal", "Novak Djokovic",
                "Stanislas Wawrinka",
                "David Ferrer","Roger Federer",
                "Andy Murray","Tomas Berdych",
                "Juan Martin Del Potro"};
        List<String> players = Arrays.asList(atp);

        //以前的循环方式
        for ( String player : players ) {
            System.out.println(player + ";");
        }

        //使用lambda表达式以及函数操作(functional operation)
        players.forEach((player)-> System.out.println(player + ";"));

        //在Java 8中使用双冒号操作符(double colon operator)
        players.forEach(System.out::println);
    }

    public void lambda_002() {

        //使用匿名内部类
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Hello World !");
            }
        }).start();

        //使用 lambda expression
        new Thread(()-> System.out.println("Hello World !")).start();

        //使用匿名内部类
        Runnable runnable_1 = new Runnable() {
            @Override
            public void run() {
                System.out.println("Hello World !");;
            }
        };

        //使用 lambda expression
        Runnable runnable_2 = () -> System.out.println("Hello World !");

        //直接调用run方法（没开新线程）
        runnable_1.run();
        runnable_2.run();
    }

    /**
     * 使用Lambdas排序集合
     * */
    public void lambda_003() {
        String[] players = {"Rafael Nadal", "Novak Djokovic",
                "Stanislas Wawrinka", "David Ferrer",
                "Roger Federer", "Andy Murray",
                "Tomas Berdych", "Juan Martin Del Potro",
                "Richard Gasquet", "John Isner"};

        //使用匿名内部类根据name排序players
        Arrays.sort(players, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o1.compareTo(o2));
            }
        });

        //使用 lambda expression排序players
        Comparator<String> sortByName = (String s1, String s2) -> (s1.compareTo(s2));
        Arrays.sort(players, sortByName);

        //也可以采用如下形式：
        Arrays.sort(players, (String s1, String s2) -> (s1.compareTo(s2)));
    }

    /**
     * 使用Lambdas和Stream
     * */
    //Stream是对集合的包装，通常和Lambda一起使用。使用Lambdas可以支持许多操作，
    //如map，filter，limit，soyted，count，min，max，sum，collect等等。
    //同样，Stream使用“懒运算”，它们并不会真正的读取所有数据，遇到像getFirst()这样的方法就会结束链式语法。
     public void lambda_004() {
         List<Person> javaProgrammers = new ArrayList<Person>() {
             {
                 add(new Person("Elsdon", "Jaycob", "Java programmer", "male", 43, 2000));
                 add(new Person("Tamsen", "Brittany", "Java programmer", "female", 23, 1500));
                 add(new Person("Floyd", "Donny", "Java programmer", "male", 33, 1800));
                 add(new Person("Sindy", "Jonie", "Java programmer", "female", 32, 1600));
                 add(new Person("Vere", "Hervey", "Java programmer", "male", 22, 1200));
                 add(new Person("Maude", "Jaimie", "Java programmer", "female", 27, 1900));
                 add(new Person("Shawn", "Randall", "Java programmer", "male", 30, 2300));
                 add(new Person("Jayden", "Corrina", "Java programmer", "female", 35, 1700));
                 add(new Person("Palmer", "Dene", "Java programmer", "male", 33, 2000));
                 add(new Person("Addison", "Pam", "Java programmer", "female", 34, 1300));
             }
         };

         List<Person> phpProgrammers = new ArrayList<Person>() {
             {
                 add(new Person("Jarrod", "Pace", "PHP programmer", "male", 34, 1550));
                 add(new Person("Clarette", "Cicely", "PHP programmer", "female", 23, 1200));
                 add(new Person("Victor", "Channing", "PHP programmer", "male", 32, 1600));
                 add(new Person("Tori", "Sheryl", "PHP programmer", "female", 21, 1000));
                 add(new Person("Osborne", "Shad", "PHP programmer", "male", 32, 1100));
                 add(new Person("Rosalind", "Layla", "PHP programmer", "female", 25, 1300));
                 add(new Person("Fraser", "Hewie", "PHP programmer", "male", 36, 1100));
                 add(new Person("Quinn", "Tamara", "PHP programmer", "female", 21, 1000));
                 add(new Person("Alvin", "Lance", "PHP programmer", "male", 38, 1600));
                 add(new Person("Evonne", "Shari", "PHP programmer", "female", 40, 1800));
             }
         };
     }

 }
