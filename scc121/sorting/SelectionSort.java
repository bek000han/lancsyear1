import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SelectionSort {
/*WRONG WRONG WRONG */
    public void sort(List<Integer> arr){
        int temp;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr.get(i) < arr.get(j)){
                    temp = arr.get(i);
                    arr.set(i, j);
                    arr.set(j, temp);
                }
            }
        }
    }

    public List<Integer> createList(int len){
        List<Integer> list = new ArrayList<Integer>();
        Random rand = new Random();

        for (int i = 0; i < len; i++) {
            list.add(rand.nextInt(20));
        }

        return list;
    }
}
