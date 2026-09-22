package ArrayList_Test;

import java.util.ArrayList;

public class Demo1 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("aaa");
        list.add("bbb");
        list.add("ccc");

        ArrayList<String> list1 = new ArrayList<>(list);
        System.out.println(list1);
    }
}