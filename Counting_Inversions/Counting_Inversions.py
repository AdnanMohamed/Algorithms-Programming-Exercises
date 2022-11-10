# -*- coding: utf-8 -*-
"""
Created on Tue May 18 07:30:09 2021

@author: adnan
"""

from random import uniform

def sort_and_count_inversions(A):
    def merge_and_count_splitInversions(B, C):
        '''
        Precondition: B, and C are sorted arrays.
        Postcondition: returns (D, count) where D is a sorted array of
        all elements in B and C, and count is the number of split inversions.
        '''
        i = j = count = 0
        N = len(B)+len(C)
        B.append(float('infinity'))
        C.append(float('infinity'))
        D = [None] * N
        for k in range(N):
            if B[i] <= C[j]:
                D[k] = B[i]
                i+=1
            else:
                D[k] = C[j]
                count+=(len(B) - i - 1)
                j+=1
        return (D, count)
    
    
    def sort_count_inversions(A):
        '''
        Returns (D, totalInversions) where D is A but sorted and
        totalInversions is the total number of inversions in A.
        '''
        N = len(A)
        if N < 2:
            return (A, 0)

        (B, x) = sort_count_inversions(A[:N//2])
        (C, y) = sort_count_inversions(A[N//2::])
        (D, z) = merge_and_count_splitInversions(B, C)
        return (D, x+y+z)
        
    return sort_count_inversions(A)

###  TEST FOR THE ABOVE CODE.  *UNCOMMENT TO TEST  ###

#for i in range(10):
#    Test = []
#    for j in range(20 * i):
#        Test.append(int(uniform(-50, 50)))
#
#    (sortedArray, inversions) = sort_and_count_inversions(Test)
#
#    print(inversions, '\n')
    

f = open("IntegerArray.txt", "rt")

nums = [int(x) for x in f if x != ""]

nums_sorted, total_inversions = sort_and_count_inversions(nums)

assert nums_sorted == [x + 1 for x in range(100000)]

print(total_inversions)