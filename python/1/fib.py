#!/usr/bin/env python3

def fib(x):
    if x < 2:
        return list(x)
    
    a, b = 0, 1
    fibList = [a, b]
    
    while b < x:            
        c = a + b       
        a = b
        b = c
        fibList.append(b) 
    return fibList
