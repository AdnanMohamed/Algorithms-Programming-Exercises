# -*- coding: utf-8 -*-
"""
Created on Fri May 28 08:20:01 2021

@author: adnan

The following algorithms are solutions for Optional Theory Problems (Batch #1)
in 'Algorithms' course in coursera taught by Tim Roughgarden
"""

from random import uniform

## QUESTION 2.

def Find_Max(A):
    '''
    Precondition:
        'A' is a unimodal array of distinct elements, meaning that 
        its entries are in increasing order up until its maximum element, 
        after which its elements are in decreasing order.
    Postcondition:
        The maximum in A is returned.
    '''
    assert len(A) > 0, "The collection is empty!"
    
    def Find_Max_helper(low, hi):
        if hi - low <= 1:
            if A[low] < A[hi]:
                return A[hi]
            else:
                return A[low]
        else:
            m = (low+hi) // 2
            
            if A[m-1] < A[m]:
#                The max is NOT in A[low..m-1] so
#                it must be in A[m..hi]
                return Find_Max_helper(m, hi)
            else:
#                max is NOT in A[m..r]
#                so it must be in A[low..m-1]
                return Find_Max_helper(low, m-1)
    
    return Find_Max_helper(0, len(A)-1)


#########  TEST for above solution  ##########
    
##  COMMENT OUT THE CODE TO TEST THE SOLTION.


#
#for i in range(5):
#    N = 2**i * 50
#    A = list({int(uniform(-N, N)) for _ in range(N)})
#    
#    largest = max(A)
#    
#    max_index = A.index(largest)
#    
#    unimodal = sorted(A[:max_index+1]) + sorted(A[max_index+1::], reverse=True)
#    
#    myMax = Find_Max(unimodal)
#    print(f'myMax = {myMax}, and max = {largest}')
#    
#    assert myMax == max(unimodal), f'{myMax} is not the max'
    
##############  END OF QUESTION 2    ##############
    

## QUESTION 3
    
#
#You are given a sorted (from smallest to largest) array A of n distinct integers 
#which can be positive, negative, or zero. You want to decide whether or not 
#there is an index i such that A[i] = i. Design the fastest algorithm that you 
#can for solving this problem.
    
def has_identity_element(A):
    '''
    Precondition: 'A' is a list/array of distinct integers sorted increasingly.
    Postcondition: Returns True iff for some i, A[i] == i, otherwise False.
    '''
    
    def helper(low, hi):
        '''
        low: left-most index
        hi: right-most index
        '''
        if hi <= low:
            return A[low] == low
        else:
            mid = (hi+low)//2
            if A[mid] == mid:
                return True
            elif A[mid] > mid:
                # Check left subset
                return helper(low, mid-1)
            else:
                # check right subset
                return helper(mid+1, hi)
    
    return helper(0, len(A) - 1)
    

#########  TEST for above solution  ##########
    
##  COMMENT OUT THE CODE TO TEST THE SOLTION.
    
#def test3(A):
#    return has_identity_element(A) == any([A[i] == i for i in range(len(A))])
#
#for _ in range(20):
#    Test_list = sorted({int(uniform(-1000, 1000)) for _ in range(1000)})
#    
#    
#    assert test3(Test_list), "test3 failed"
    
    
##############  END OF QUESTION 2    ##############    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    