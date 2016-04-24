import sys
import os
 
def factorial(number):
	# this function gives factorial of a given number
	if(number==0):
		return 1
	return number*factorial(number-1)
 
# N is number of test cases
N = int (sys.stdin.readline())
for i in range(N):
	x = int (sys.stdin.readline())
	print factorial(x) 
