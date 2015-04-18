package com.glacier.test;

import java.util.ArrayList;
import java.util.List;

class ToList<E>{
    private static List list;
    private static ToList toList ;

    public ToList(){
        list = new ArrayList(10);
        toList = this;
    }

    public static ToList create( Object... objects ){
        toList = new ToList<Object>();
        for (Object object : objects) {
            toList.list.add(object);
        }
        return toList;
    }
    public ToList add(E... arr){
        for (E a : arr){
            list.add(a);
        }
        return this;
    }

    public List<E> toList(){
        return list;
    }
}
