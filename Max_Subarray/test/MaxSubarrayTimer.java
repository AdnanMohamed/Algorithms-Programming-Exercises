import java.util.concurrent.ThreadLocalRandom;

/**
 * This class times the two implementations of maxSubarray
 * to compare the two algorithms
 * @author adnan
 *
 */
public class MaxSubarrayTimer {
    
    public static void main(String[] args) {
        final int N = 10000000;  // array size
        int min = -2*N, max = 2*N;
        
        int k = 10;
        int[][] a = new int[k][];
        for(int i = 0; i < k; ++i) {
            a[i] = createRandomArray(min, max, N);
        }
        
        final long start = System.currentTimeMillis();
        System.out.println("Start time (s): " + start);
        
        int res[][] = new int[k][];
        for(int i = 0; i < k; ++i) {
            res[i] = MaxSubarray.findMaxSubarray1(a[i]);
        }
        final long end = System.currentTimeMillis();
        System.out.println("Start time (s): " + end);
        final long totalTime = (end - start);
        final long avgTime = totalTime/k;
        
        System.out.println("Average Time (s): " + avgTime);
        
        return;
    }

    private static int[] createRandomArray(int min, int max, int n) {
        int[] res = new int[n];
        for(int i = 0; i < n; ++i) {
            res[i] = ThreadLocalRandom.current().nextInt(min, max + 1);
        }
        return res;
    }
}
