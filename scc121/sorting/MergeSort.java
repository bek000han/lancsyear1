public class MergeSort {
    public static void main(String[] args) {
        int [] arr = {5,7,1,9,2,3,4,8,0,6};
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.err.println("\nsorted:");
        mergeSort(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    private static void mergeSort(int[] arr){
        if (arr.length <= 1){
            return;
        }

        int mid = arr.length / 2;
        int[] left = new int[mid];
        int[] right = new int[arr.length - mid];

        int i = 0, j = 0;
        for (; i < arr.length; i++) {
            if (i < mid) {
                left[i] = arr[i];
            } else {
                right[j] = arr[i];
                j++;
            }
        }

        mergeSort(left);
        mergeSort(right);
        merge(arr, left, right);
    }

    private static void merge(int[] arr, int[] left, int[] right){
        int leftSize = arr.length / 2;
        int rightsize = arr.length - leftSize;
        int l = 0, r = 0, i = 0;

        while(l < leftSize && r < rightsize){
            if (left[l] < right[r]){
                arr[i] = left[l];
                i++;
                l++;
            } else {
                arr[i] = right[r];
                i++;
                r++;
            }
        }
        while(l < leftSize) {
            arr[i] = left[l];
            i++;
            l++;
        }
        while(r < rightsize) {
            arr[i] = right[r];
            i++;
            r++;
        }
    }
}
