/**
 * This class implements the maximum subarray algorithm. Where the algorithm
 * takes an array of numbers and returns the subarray that has maximum sum.
 * For more details about the algorithm, see CLRS section 4.1
 * 
 * 
 * @author adnan
 *
 */
public class MaxSubarray {
    /**
     * Gets the boundaries of the subarray with maximum sum and its sum
     * @param a an array with at least one integer
     * @return an array, res[], where res[0], res[1] defines the first and last
     *         index of the max. subarray of a, and res[2] has the sum of the 
     *         subarray.
     */
    public static int[] findMaxSubarray1(int[] a) {
        return findMaxSubarrayRecursive(a, 0, a.length-1);
    }
    
    public static int[] findMaxSubarray2(int[] a) {
        return findMaxSubarrayBruteForce(a, 0, a.length-1);
    }    

    /**
     * @param a is an array with at least one integer 
     * @param left is the index of first element
     * @param right is the index of the last element
     * @return an array, res[], where res[0], res[1] demarcates the first and last
     *         indices of a max. subarray of a, and res[2] is the sum of that
     *         max. subarray
     */
    private static int[] findMaxSubarrayRecursive(int[] a, int left, int right) {
        if(left == right) {
            return new int[] {left, left, a[left]};
        }
        int mid = (left + right)/2;
        int[] resLeft  = findMaxSubarrayRecursive(a, left, mid);
        int[] resRight = findMaxSubarrayRecursive(a, mid+1, right);
        int[] resCross = maxSubarrayCrossOver(a, left, mid, right);
        
        if(resLeft[2] >= resRight[2] && resLeft[2] >= resCross[2]) {
            return resLeft;
        }
        else if(resRight[2] >= resLeft[2] && resRight[2] >= resCross[2]) {
            return resRight;
        }
        else {
            return resCross;
        }
    }
    
    /**
     * Gets the boundaries and sum of the maximum subarray of a[left..right]
     * that passes through the middle
     * @param a is an array with at least 2 elements
     * @param left the first index of a that specifies the index of the left boundary
     * @param mid  is the midpoint of the subarray of a, left<=mid<right
     * @param right is the last index of the subarray of a
     * @return an array, res[], such that res[0] & res[1] specify the boundaries
     *         of the maximum subarray of 'a' that has at least one element in
     *         a[left..mid] and at least one element in a[mid+1..right] 
     */
    static int[] maxSubarrayCrossOver(int[] a, int left, int mid, int right) {
        int low=0, hi=0;
        int lsum = 0;
        int lmax = Integer.MIN_VALUE;
        
        for(int i = mid; i >= left; --i) {
            lsum += a[i];
            if(lsum > lmax) {
                lmax = lsum;
                low = i;
            }
        }
        
        int rsum = 0;
        int rmax = Integer.MIN_VALUE;
        for(int i = mid+1; i <= right; ++i) {
            rsum += a[i];
            if(rsum > rmax) {
                rmax = rsum;
                hi = i;
            }
        }
        
        return new int[] {low, hi, lmax + rmax};
    }
    
    private static int[] findMaxSubarrayBruteForce(int[] a, int left, int right) {
        int max = Integer.MIN_VALUE;
        int idx1 = left, idx2 = left;
        for(int i = 0; i < a.length; ++i) {
            int sum = 0;
            for(int j = i; j < a.length; ++j) {
                sum += a[j];
                if(sum > max) {
                    max = sum;
                    idx1 = i;
                    idx2 = j;
                }
            }
        }
        return new int[]{idx1, idx2, max};
    }
}
