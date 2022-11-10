# -*- coding: utf-8 -*-
"""
Created on Tue May 25 16:22:16 2021

@author: adnan
"""

from math import sqrt, ceil, floor

def closest_pair(P):
    '''
    Precondition: P is a collection of points in a plane.
    Postcondition: (p, q, d) where p and q are the pair of closest
    points in P, and d is the distance between them.
    '''

    P = list(P)
    X = sorted(P, key=lambda elem:elem[0])
    Y = sorted(P, key=lambda elem:elem[1])
    
    
    def closest_pair_helper(X, Y):
        if len(X) <= 3:
            return brute_force(X)
        
        m = 0
        XL = []
        XR = []
         
        XL, XR = splitX(X)
        m = get_median(X)


        YL, YR = splitY(Y, m)
        
        p1, q1, d1 = closest_pair_helper(XL, YL)
        p2, q2, d2 = closest_pair_helper(XR, YR)
        d = min(d1, d2);
        
        V = [p for p in Y if p[0] > m - d and p[0] < m+d]

        p3, q3, d3 = split_closest_pair(m, V, d)

        
        if d3 < d:
            return (p3, q3, d3)
        
        if d == d1:
            return p1, q1, d1
        else:
            return p2, q2, d2
        
    def brute_force(P):
        best_dist = float('inf')
        p = q = None
        for i in range(len(P)):
            for j in range(i+1, len(P)):
                d = dist(P[i], P[j])
                if d < best_dist:
                    best_dist = d
                    p, q = P[i], P[j]
        return (p, q, best_dist)
    
    def dist(p, q):
        '''
        Returns the euclidean distance between points p and q in the x-y plane.
        '''
        d = sqrt((p[0] - q[0])**2 + (p[1] - q[1])**2)
        return round(d, 3)
    
    def splitX(X):
        '''
        precondition: 
            X is a list of points (x, y) and sorted increasing by x-coordinate. (N is the length of X)
        postcondition:
            Returns XL, XR where XL is the left half of X whereas XR is the right half of X.
            XL.Length == ceil(N/2) and XR == floor(N/2). Consequently, both XL, XR are in increasing
            order by x-coordinates (since X is sorted by the precondition)
        '''
        
        N = len(X)
        
        mid = ceil(N/2)
        XL = X[:mid]
        XR = X[mid::]
        
        return XL, XR
    
    def splitY(Y, m):
        '''
        Precondition: 
            Y is a list of points sorted increasing by y-coordinate (N is Y's length)
            m is the median to be split on.
        Postcondition:
            Returns YL, YR. YL := {(x, y) | x < m} union ~half the points where x == m
            YR := {(x, y) | x > m} union ~half the points where x == m
            YL.Length == ceil(N/2) and YR == floor(N/2).
            YL and YR are increasingly sorted by y-coordinate
        '''
        left_subset = []
        right_subset = []
        N = len(Y)
        left = True
                
        for i in range(N):
            if Y[i][0] < m:
                left_subset.append(Y[i])
            elif(Y[i][0] > m):
                right_subset.append(Y[i])
            elif Y[i][0] == m and left:
                left_subset.append(Y[i])
                left = False
            elif(Y[i][0] == m):
                right_subset.append(Y[i])
                left = True
                
        return left_subset, right_subset
    
    def get_median(X):
        '''
        Precondition: 
            X is a list of points increasingly sorted by x-coordinates.
        Postcondition:
            Returns the median of the x values.
            In case 2 medians, the average of the medians is returned.
        '''
        mid = floor(len(X) / 2)
        if len(X) % 2 == 1:
            return X[mid][0]
        else:
            return (X[mid][0]+X[mid-1][0]) / 2             
        
    def split_closest_pair(m, V, d):
        best_dist = d
        p = q = None        
        for i in range(len(V) - 1):
            for j in range(i+1, min(i+8, len(V))):
                distance = dist(V[i], V[j])
                if distance < best_dist:
                    best_dist = distance
                    p, q = V[i], V[j]
        return (p, q, best_dist)
    
    
    return closest_pair_helper(X, Y)

from random import uniform

P = {(round(uniform(-500, 500), 1), round(uniform(-250, 250), 1)) for _ in range(100000)}

#P = {(-1.94, -3.66), (-0.51, -6.78), (5.88, 6.95), (-3.15, -2.77), (1.74, 6.13), (6.69, -5.56), (0.93, -5.75), (5.14, -1.71), (-8.27, -3.05), (0.15, 6.63), (-5.5, 4.61), (2.42, -6.18), (5.51, 4.72), (0.48, -0.63), (7.58, -8.23), (-6.35, 5.44), (-4.3, -0.56), (-4.54, 4.82), (6.76, 1.42), (8.46, -4.67)}

print("The set of points:\n", P)
print()

print("The closest pair:", closest_pair(P))