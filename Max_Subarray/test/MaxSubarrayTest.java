import static org.junit.Assert.*;

import java.util.Arrays;
import java.util.stream.IntStream;

import org.junit.Test;

/**
 * Test suite for MaxSubarray class
 * @author adnan
 *
 */
public class MaxSubarrayTest {
    /* Testing Strategy:
     * 
     *  partition input:
     *   a.length = 1, 2, >2
     *   
     *   max. subarray place: left half, cross-over, right half
     *   
     *   Include odd and even length arrays which have length >2 because
     *   in odd length the array cannot be divided equally into two halves
     *   
     *   Uses White-box testing
     *   
     *   Coverage: covers all (possible) parts
     * 
     */
    
    /*
     *  covers: a.length = 1
     */
    @Test
    public void testfindMaxSubarray11(){
        int[] a = {5};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        assertEquals(0, res[0]);
        assertEquals(0, res[1]);
        assertEquals(a[0], res[2]);
    }
    
    /*
     *  covers: a.length = 2,
     *          max subarray pos. : left half
     */
    @Test
    public void testfindMaxSubarray12(){
        int[] a = {7, -2};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        assertEquals(0, res[0]);
        assertEquals(0, res[1]);
        assertEquals(a[0], res[2]);
    }
    
    /*
     *  covers: a.length = 2,
     *          max subarray pos. : right half
     */
    @Test
    public void testfindMaxSubarray13(){
        int[] a = {-2, 7};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        assertEquals(1, res[0]);
        assertEquals(1, res[1]);
        assertEquals(a[1], res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : left half
     *          array.length is odd
     */
    @Test
    public void testfindMaxSubarray14(){
        int[] a = {13, 2, -12, 10, 1};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 0, right = 1;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : left half
     *          array length is even
     */
    @Test
    public void testfindMaxSubarray15(){
        int[] a = {13, -1, 2, -10, 1, 5};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 0, right = 2;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : right half
     *          array length is odd
     */
    @Test
    public void testfindMaxSubarray16(){
        int[] a = {1, 10, -12, 13, 2};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 3, right = 4;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : right half
     *          array length is even
     */
    @Test
    public void testfindMaxSubarray17(){
        int[] a = {-10, 1, -5, 13, -3, 4};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 3, right = 5;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : cross-over
     *          array length is odd
     */
    @Test
    public void testfindMaxSubarray18(){
        int[] a = {-10, 1, 5, 13, -3};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 1, right = 3;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : cross-over
     *          array length is even
     */
    @Test
    public void testfindMaxSubarray19(){
        int[] a = {3, -10, 2, -1, 5, 13, -3, 2};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 2, right = 5;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  covers: a.length = >2,
     *          max subarray pos. : entire array
     */
    @Test
    public void testfindMaxSubarray110(){
        int[] a = {3, 1, 2, 1, 5, 13, 3, 2};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 0, right = a.length-1;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     *  extra test
     */
    @Test
    public void testfindMaxSubarray111(){
        int[] a = {13, -3, -25, 20, -3, -16, -23, 18, 20, 
                   -7, 12, -5, -22, 15, -4, 7};
        int[] res = MaxSubarray.findMaxSubarray1(a);
        assertTrue(res.length == 3);
        int left = 7, right = 10;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     * Testing Strategy
     * 
     * input space partition:
     *  a.length: 2, >2
     *  Include even and odd length arrays
     *  
     *  output space partitions:
     *  res[0] = mid   |  left < res[0] < mid | res[0] = left 
     *  res[1] = mid+1 | mid+1 < res[1] < mid | res[1] = right
     */
    
    /*
     * covers a.length = 2,
     *        a.length is even,
     *        res[0] = mid,
     *        res[1] = mid+1
     */
    @Test
    public void testMaxSubarrayCrossOver1() {
        int[] a = new int[] {-3, 1};
        
        int m = (a.length-1)/2;
        int[] res = MaxSubarray.maxSubarrayCrossOver(a, 0, m, a.length-1);
        assertTrue(res.length == 3);
        int left = 0, right = 1;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     * covers a.length > 2,
     *        a.length is even,
     *        res[0] = mid,
     *        res[1] = mid+1
     */
    @Test
    public void testMaxSubarrayCrossOver2() {
        int[] a = new int[] {-9, -3, 1, -5};
        
        int m = (a.length-1)/2;
        int[] res = MaxSubarray.maxSubarrayCrossOver(a, 0, m, a.length-1);
        assertTrue(res.length == 3);
        int left = 1, right = 2;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     * covers a.length > 2,
     *        a.length is odd,
     *        res[0] = mid,
     *        res[1] = mid+1
     */
    @Test
    public void testMaxSubarrayCrossOver3() {
        int[] a = new int[] {-9, 3, 1, -5, -1};
        
        int m = (a.length-1)/2;
        int[] res = MaxSubarray.maxSubarrayCrossOver(a, 0, m, a.length-1);
        assertTrue(res.length == 3);
        int left = 1, right = 3;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     * covers a.length > 2,
     *        a.length is even,
     *        left < res[0] < mid,
     *        res[1] = mid+1
     */
    @Test
    public void testMaxSubarrayCrossOver4() {
        int[] a = new int[] {-1, 2, 3, 1, -5, -1};
        
        int m = (a.length-1)/2;
        int[] res = MaxSubarray.maxSubarrayCrossOver(a, 0, m, a.length-1);
        assertTrue(res.length == 3);
        int left = 1, right = 3;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
    
    /*
     * covers a.length > 2,
     *        a.length is odd,
     *        left < res[0] < mid,
     *        res[1] = mid+1
     */
    @Test
    public void testMaxSubarrayCrossOver5() {
        int[] a = new int[] {-1, 2, 3, 1, 5, -1, -2};
        
        int m = (a.length-1)/2;
        int[] res = MaxSubarray.maxSubarrayCrossOver(a, 0, m, a.length-1);
        assertTrue(res.length == 3);
        int left = 1, right = 4;
        assertEquals(left, res[0]);
        assertEquals(right, res[1]);
        int expectedSum = IntStream.of(Arrays.copyOfRange(a, left, right+1)).sum();
        assertEquals(expectedSum, res[2]);
    }
}
