import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        int [] arr = {3,7,12,46,78,93,174,208,300,670};
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println("\n0 1  2  3  4  5   6   7   8   9");
        System.err.print("\nFind int: ");
        
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        sc.close();
        System.out.println("\n" + num + " is at index: " + binarySearch(arr, num));
    }

    private static int binarySearch(int[] arr, int num){
        int lo = 0, hi = arr.length, mid = lo + (hi - lo) / 2;
        while(mid != lo){
            if (arr[mid] == num){
                return mid;
            } else {
              if (arr[mid] > num) {
                hi = mid;
              } else {
                lo = mid;
              }
            }
            mid = (lo + hi) / 2;
        }
        return -1;
    }
}
