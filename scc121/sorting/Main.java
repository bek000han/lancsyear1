import java.util.List;

public class Main{
    public static void main (String[] args){
        SelectionSort test = new SelectionSort();
        List<Integer> list = test.createList(10);
        System.out.println(list);
        test.sort(list);
        System.out.println(list);
    }
}