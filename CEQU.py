#possibility of having solution of ax+by=c for integers x,y.
 
import sys
 
from fractions import gcd
 
t = int(input())
 
for i in range(1, t+1):
	[a, b, c] = map(int, sys.stdin.readline().split())
	if c % gcd(a, b) == 0:
		print 'Case', str(i)+': Yes'
	else:
		print 'Case', str(i)+': No' 
