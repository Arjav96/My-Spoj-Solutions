import os
import sys
"""
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
 
t = int(raw_input())
for i in range(t):
	
	a , b= map(int ,sys.stdin.readline().split())
	print gcd(a,b)
"""
 
def gcd (a, b):
	if b == 0:
		return a
	else:
		return gcd (b, a % b)
 
t = int ( input() )
 
while t != 0:
	t = t - 1
	a, b = [int(x) for x in input().split()]
	print (gcd(a, b)) 
