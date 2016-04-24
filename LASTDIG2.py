import os
import sys
 
# This function calculates (a ** b)%c 
# pow(a,b,c) (a ** b)%c
"""def modulo(a,b,c):
	x = 1
	y = a
	while b > 0:
		if b % 2 == 1:
			x = (x * y) % c
        	y = (y * y) % c  # squaring the base
        	b /= 2
	return x % c
"""
 
 
# N is number of test cases
N = int (sys.stdin.readline())
 
for i in range(N):
	x ,y = map(int, sys.stdin.readline().split(' '))
	ans = pow(x , y , 10)
	print ans 
