# -*- coding: utf-8 -*-
"""
Created on Mon May 31 07:57:15 2021

@author: adnan

This program answers the question in Programming Assignment #3 Algorithms
course coursera. 
"""

from random import randint


def quicksort_and_count(A):
    '''
    Precondition: 'A' is a list (or any subscriptable object)
    that contains elements which can be compared using <=, > , ...
    Postcondition: 'A' is sorted (in place) and the number of comparisons
    made by the 'partition' procedure (see above) is returned.
    
    This is to compare the effect of the pivot choice on the number of 
    comparisons done in quicksort.
    '''
    count = 0
    def sort_helper(l, r):
        if l < r:
            p = partition(l, r)
            sort_helper(l, p-1)
            sort_helper(p+1, r)            
    
    def partition(l, r):
        '''
        Rearranges the array A (the input list to quicksort) such that:
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
        nonlocal count
        count += r-l
        q = pivot3(l, r)  # pick a random index to be the pivot index
        A[r], A[q] = A[q], A[r]  # swap the pivot with the last element
        x = A[r]
        i = l-1
        for j in range(l, r):
            if A[j] <= x:
                i += 1
                A[i], A[j] = A[j], A[i]
        
        A[i+1], A[r] = A[r], A[i+1]
        return i+1
    
    def pivot1(i, j):
        '''
        Returns i (for the pivot index)
        '''        
        return i


        
    def pivot2(i, j):
        '''
        Returns j (for the pivot)
        '''
        return j
    
    def pivot3(i, j):
        '''
        Returns the median of i, j, and (i+j)//2
        '''
        m = (j+i-1)//2
        if (A[i] <= A[m] <= A[j]) or (A[j] <= A[m] <= A[i]):
            return m
        elif (A[m] <= A[i] <= A[j]) or (A[j] <= A[i] <= A[m]):
            return i
        else:
            return j
            
        
        
    def pivot4(i, j):
        '''
        Returns a random index from i to j (inclusive)
        '''
        return randint(i, j)
        
    sort_helper(0, len(A)-1)   # sorts the whole list (array)
    
    return count

###  UNCOMMENT THE CODE BELOW TO TEST QUICKSORT   ######

#totalcomparisons = 0
#trials = 300
#for i in range(trials):
#    n = 1000
#    a = [randint(1, n) for _ in range(n)]
#    
#    totalcomparisons+= quicksort_and_count(a)
#    
#    assert a == sorted(a), "your quicksort has a bug"
#
#avgcomparisons = totalcomparisons // trials
#print(avgcomparisons)
#######    END OF TESTS   ###########

#
#def main():
#    
#    ia = []
#    f = open('QuickSort_input.txt', 'r')
#    ls = f.readlines()
#    f.close()
#    ia = [int(i) for i in ls]
#    
#    print(quicksort_and_count(ia))
#    assert ia == sorted(ia)
#    
#if __name__ == "__main__":
#    main()