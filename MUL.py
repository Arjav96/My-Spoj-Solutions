# your code goes here
 
import sys
import os
 
 
# N is number of test cases
N = int (sys.stdin.readline())
# This loop is equivalent to for ( int i = 0; i < N; ++i)
for i in range(N):
	x, y = map(int, sys.stdin.readline().split(' '))
	print x*y 
