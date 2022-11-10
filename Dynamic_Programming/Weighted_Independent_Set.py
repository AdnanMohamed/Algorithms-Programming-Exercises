# -*- coding: utf-8 -*-
"""
Created on Tue Aug 24 10:12:42 2021

@author: adnan
"""

def WIS(V):
    w = []
    for v in V:
        w.append(v)
    w = [0] + w
    A = [0, w[1]] + [inf]