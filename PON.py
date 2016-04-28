import sys
import os
import random
 
# Primality test: Rabin Miller
 
 
# This function calculates (a^b)%c 
def modulo( a,b,c):
	x=1
	y=a
	while b>0:
		if b%2 == 1:
			x=(x*y)%c
        	y = (y*y)%c  # squaring the base
        	b /= 2
	return x%c
 
 
 
# this function calculates (a*b)%c taking into account that a*b might overflow 
def mulmod(a,b,c):
	x = 0
	y=a%c
	while b > 0:
	        if b%2 == 1:
			x = (x+y)%c
        	y = (y*2)%c
        	b /= 2
	return x%c
 
 
 
# Miller-Rabin primality test, iteration signifies the accuracy of the test 
def Miller( p, iteration):
	if p<2:
	        return False
   	if p!=2 and p%2==0:
        	return False
    	s=p-1
    	while s%2==0:
		s/=2
   	for i in range(iteration):
        	a= random.randint(0,p)  #err
		temp=s
        	mod=modulo(a,temp,p)
        while temp!=p-1 and mod!=1 and mod!=p-1:
            	mod=mulmod(mod,mod,p)
            	temp *= 2
 
        if mod!=p-1 and temp%2==0:
            	return False
        
    
   	return True
 
 
# N is number of test cases
N = int (sys.stdin.readline())
 
for i in range(N):
	x = int (sys.stdin.readline())
	 
	if Miller(x,18):
		print 'YES'
	else:
		print 'NO' 
