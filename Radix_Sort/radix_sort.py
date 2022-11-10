# -*- coding: utf-8 -*-
"""
Created on Thu Jun  3 07:05:08 2021

@author: adnan
"""
from random import randint

def radix_sort(A):
    '''
    Precondition: A- input list of nonegative integers.
    Postcondition: Sorts 'A'.
    '''
    def Counting_Sort(A, k, p):       
        C = [0]*(k+1)
        B = [None] * len(A)
        
        for j in range(len(A)):
            digit = (A[j] // pos) % 10
            C[digit] += 1
            
        # now C[i] = no. of elements in A equal to i
        
        for i in range(1, k+1):
            C[i] = C[i] + C[i-1]
        
        # C[i] now has the no. of elements equal to or less than i in A
        for j in range(len(A)-1, -1, -1):
            digit = (A[j] // pos) % 10
            C[digit] -= 1
            B[C[digit]] = A[j]
        
        for i in range(len(A)):
            A[i] = B[i]
    
    
    m = max(A)
    
    pos = 1
    while m // pos > 0:
        k = max(A, key= lambda x: (x // pos) % 10)
        Counting_Sort(A, k, pos)
        pos *= 10



####  UNCOMMENT THE CODE BELOW TO TEST QUICKSORT   ######

trials = 3
for i in range(trials):
    n = 10000
    a = [randint(0, n**2) for _ in range(n)]
    
    radix_sort(a)
    
    assert a == sorted(a), "Your radix sort has a bug"

########    END OF TESTS   ###########