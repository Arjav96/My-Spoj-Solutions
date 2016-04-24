import sys
import os
 
for i in range(10):
	x = long (sys.stdin.readline())
	y = long (sys.stdin.readline())
	if ( x%2==0 and y%2==0 or x%2!=0 and y%2!=0 ):
		print (x+y)/2
		print (x-y)/2
	 
