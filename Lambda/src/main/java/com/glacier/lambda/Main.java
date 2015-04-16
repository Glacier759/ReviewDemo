package com.glacier.lambda;

import com.glacier.lambda.pojo.Person;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Predicate;
import java.util.stream.Stream;

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
        obj.lambda_003();
        obj.lambda_004();
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

         //使用forEach语句与Lambda表达式输出集合内容
         System.out.println("所有程序员的姓名");
         javaProgrammers.forEach((programmer)-> System.out.printf("%s %s;\n", programmer.getFirstName(), programmer.getLastName()));
         phpProgrammers.forEach((programmer)-> System.out.printf("%s %s;\n", programmer.getFirstName(), programmer.getLastName()));

         //使用forEach语句与Lambda表达式增加程序员的工资5%
         System.out.println("给程序员加薪 %5: ");
         //暂时理解为为集合中是所有元素创建公式，通过后面的forEach语句遍历集合同时执行此操作
         Consumer<Person> giveRaise = e -> e.setSalary(e.getSalary() / 100 * 5 + e.getSalary());    //java.util.function

         System.out.println("加薪前");
         javaProgrammers.forEach(System.out::println);  //执行操作
         System.out.println("加薪后");
         javaProgrammers.forEach(giveRaise);
         javaProgrammers.forEach(System.out::println);
         phpProgrammers.forEach(giveRaise);

         //使用过滤器filter()显示月薪超过1400美元的PHP程序员
         System.out.println("月薪超过1400美元的PHP程序员");
         phpProgrammers.stream()
                 .filter((p)->(p.getSalary() > 1400))
                 .forEach(System.out::println);

         //定义filters
         //暂时理解为，Predicate为一个集合定义过滤器，要求这个集合中的所有元素满足后面lambda表达式的条件
         //Predicate是一个接口，Java 8中接口允许实现，实现采用Lambda表达式，英文字面释义“断定为，断定性的”，此处理解为过滤器
         //test方法通过传入一个过滤器泛型表示的对象，判断该对象是否满足当前过滤条件，如果满足则返回true
         //and方法通过参数传入一个过滤器，要求结果同时满足两个过滤器
         //negate方法相当于对过滤器进行了一次逻辑上的取反操作
         //or方法通过参数传入一个过滤器，要求结果只要满足其一即可
         Predicate<Person> ageFilter = (p) -> (p.getAge() > 25);
         Predicate<Person> salaryFilter = (p) -> (p.getSalary() > 1400);
         Predicate<Person> genderFilter = (p) -> ("female".equals(p.getGender()));

         System.out.println("下面是年龄大于 24岁且月薪在$1400以上的女程序员：");
         Stream<Person> streams = phpProgrammers.stream();
         Stream<Person> streams_after_filter = streams.filter(ageFilter)
                 .filter(salaryFilter)
                 .filter(genderFilter);
         streams_after_filter.forEach(System.out::println);

         //重用filter
         System.out.println("年龄大于 24岁的女性 Java programmers: ");
         javaProgrammers.stream()
                 .filter(ageFilter)
                 .filter(genderFilter)
                 .forEach(System.out::println);

         //使用limit方法，可以限制结果集的个数
         System.out.println("最前面的三个Java Programmers");
         javaProgrammers.stream()
                 .limit(3)
                 .forEach(System.out::println);
         System.out.println("最前面的三个女性Java Programmers： ");
         javaProgrammers.stream()
                 .filter(genderFilter)
                 .limit(3)
                 .forEach(System.out::println);

         //使用stream进行排序
         System.out.println("根据name排序，并显示前5个Java Programmers：");
     }

 }
