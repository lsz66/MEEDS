import java.util.Arrays;

public class QuickSort {

    private static int round = 0;

    private static int partition(int[] a, int low, int high) {
        int pivot = a[low];     //选取每一个子序列的第一个元素作为枢轴
        while (low < high) {
            while (low < high && a[high] >= pivot)
                --high;
            a[low] = a[high];
            while (low < high && a[low] <= pivot)
                ++low;
            a[high] = a[low];
        }
        a[low] = pivot; //此时low左侧比枢轴小，右侧比枢轴大
        System.out.println("Round " + (++round) + ": " + Arrays.toString(a) + ", pivot = " + pivot);
        return low;
    }

    private static void quickSort(int[] a, int low, int high) {
        if (low < high) {   //递归边界。
            int pos = partition(a, low, high);
            quickSort(a, low, pos - 1);
            quickSort(a, pos + 1, high);
        }
    }

    private static void quickSort(int[] a) {
        quickSort(a, 0, a.length - 1);
    }

    public static void main(String[] args) {
        int[] a = {25, 14, 21, 47, 15, 27, 68, 35, 20};
        quickSort(a);
        System.out.println(Arrays.toString(a));
    }
}
