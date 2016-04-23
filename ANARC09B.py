import os
import sys
 
def gcd(m,n):
	if n==0:
		return m
	return gcd(n,m%n)
 
 
x, y = map(int, sys.stdin.readline().split())
while x!=0 and y!=0:
	if x == y:
		print 1
	elif x > y:
		if x%y == 0:
			print (x/y)
		else:
			print ((x*y)/gcd(x,y))
	elif y > x:
		if y%x == 0:
			print (y/x)
		else:
			print ((x*y)/gcd(x,y))
	x, y = map(int, sys.stdin.readline().split()) 
