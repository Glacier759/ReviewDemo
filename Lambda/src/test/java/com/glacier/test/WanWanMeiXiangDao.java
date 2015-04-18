package com.glacier.test;

/**
 * Created by IntelliJ IDEA on 2015-04-18 10:28.
 * Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 * Company: Class 1204 of Computer Science and Technology
 */
public class WanWanMeiXiangDao {
    public static void main(String[] args) {
        try (DaChuiCareer daChui = new DaChuiCareer()) {
            daChui.happyLife();
            return;
        } catch (Exception e) {
            System.out.println(e.getClass().getSimpleName());
            return;
        } finally {
            System.out.println("story end");
            return;
        }
    }
    public static class DaChuiCareer implements AutoCloseable {
        public DaChuiCareer() {
            System.out.println("born");
        }
        public void happyLife() throws JoyfulException {
            System.out.println("happy living");
            throw new JoyfulException();
        }
        @Override
        public void close() throws UnexpectedException {
            System.out.println("unexpected");
            throw new UnexpectedException();
        }
    }
}
class JoyfulException extends Exception{}
class UnexpectedException extends Exception {}