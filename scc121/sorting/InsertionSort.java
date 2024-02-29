public class InsertionSort {
    public static void main(String[] args) {
        int [] arr = {5,7,1,9,2,3,4,8,0,6};
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.err.println("\nsorted:");
        insertionSort(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    private static void insertionSort(int[] arr){
        int temp;
        int j;
        int k;
        for (int i = 1; i < arr.length; i++) {
            temp = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > temp){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}
