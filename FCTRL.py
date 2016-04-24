 
import sys
import os
# Function to return trailing 0s in factorial of n
def findTrailingZeros(n):
	# Initialize result
	count = 0
	# Keep dividing n by powers of 5 and update count
	i = 5
	while (n/i>=1):
		count += n/i
		i*=5 
	return count;
 
# N is number of test cases
N = int (sys.stdin.readline())
 
for i in range(N):
	x = int (sys.stdin.readline())
	a = findTrailingZeros(x)
	print a 
