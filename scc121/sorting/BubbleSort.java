public class BubbleSort {
    public static void main(String[] args) {
        int [] arr = {5,7,1,9,2,3,4,8,0,6};
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.err.println("\nsorted:");
        bubbleSort(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    private static void bubbleSort(int[] arr){
        int temp;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
