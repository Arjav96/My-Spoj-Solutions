# your code goes here
#!/usr/bin/env python
import sys
import os
 
def reverse(number):
	# this function reverses a given number
	result = 0
	while number > 0:
		result = number % 10 + result * 10
		number /= 10
	return result 
 
# N is number of test cases
N = int (sys.stdin.readline())
# This loop is equivalent to for ( int i = 0; i < N; ++i)
for i in range(N):
	x, y = map(int, sys.stdin.readline().split(' '))
 	x = reverse(x)
	y = reverse(y)
	print reverse(x + y) 
