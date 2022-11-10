# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 08:41:21 2021

@author: adnan
"""

from random import randint

def randomized_select(A, i):
    '''
    Precondition:
        A -- a list of N elements (N == len(A))
        i -- an integer in [1..N].
    Postcondition:
        The ith smallest element in A is returned.
        [   e.g. randomized([3, 6, 1], 3) == 6  ]
    '''
    
    def randomized_partition(l, r):
        '''
        Rearranges the array A such that:
        A[l..i] <= A[i+1] < A[i+2..r] and i+1 is returned.
        In otherwords, this procedure "partitions" the list 'A' around 
        the pivot element (A[i+1]) and its index (i+1) is returned.
        
        Stating this as postcondition:
            i+1 is returned which is the index of the "pivot element",
            where the pivot element is in the right place (it is where it should be in the sorted list A)
            and elements to the left of the pivot (if any) are less than or equal to
            the pivot whereas elements to the right of the pivot (if any) are strictly
            greater than the pivot.
        '''
        q = pivot(l, r)  # pick a random index to be the pivot index
        A[r], A[q] = A[q], A[r]  # swap the pivot with the last element
        x = A[r]
        i = l-1
        for j in range(l, r):
            if A[j] <= x:
                i += 1
                A[i], A[j] = A[j], A[i]
        
        A[i+1], A[r] = A[r], A[i+1]
        return i+1

    def pivot(i, j):
        '''
        Returns a random index from i to j (inclusive)
        '''
        return randint(i, j)
    
    def rand_select_helper(p, r, j):
        if p == r:
            return A[p]
        
        q = randomized_partition(p, r)
        k = q - p
        if k == j:
            return A[q]
        elif j < k:
            return rand_select_helper(p, q-1, j)
        else:
            return rand_select_helper(q+1, r, j-k -1)

    return rand_select_helper(0, len(A)-1, i-1)        
    

####  UNCOMMENT THE CODE BELOW TO TEST QUICKSORT   ######


#trials = 2000
#for i in range(trials):
#    n = 500
#    a = list({randint(1, n*n) for _ in range(n)})
#    
#    m = randint(1, len(a))
#    answer = randomized_select(a, m)
#    b = sorted(a)
##    print(b)
##    print(f'{m}th order-stat: {answer}')
##    print()
#    assert b[m-1] == answer, "your code is buggy"
########    END OF TESTS   ###########




