public class SelectionSort {
    public static void main(String[] args) {
        int [] arr = {5,7,1,9,2,3,4,8,0,6};
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.err.println("\nsorted:");
        selectionSort(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    private static void selectionSort(int[] arr){
        for (int i = 0; i < arr.length - 1; i++){
            int min = i;
            for (int j = i + 1; j < arr.length; j++){
                if (arr[min] > arr[j]){
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
