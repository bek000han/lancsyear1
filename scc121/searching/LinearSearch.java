public class LinearSearch {
    public static void main(String[] args) {
        int [] arr = {5,7,1,9,2,3,4,8,0,6};
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.err.println();
        System.out.println("4 is at index: " + linearSearch(arr, 4));
    }

    private static int linearSearch(int[] arr, int num){
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num){
                return i;
            }
        }
        return -1;
    }
}
