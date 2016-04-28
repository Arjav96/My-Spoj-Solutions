# quad area based on Brahmagupta's formula : http://en.wikipedia.org/wiki/Brahmagupta's_formula
 
import math
import sys
 
t = int(raw_input())
for i in range(t):
	a , b , c , d = map(float ,sys.stdin.readline().split(' '))
	s = (a+b+c+d) / 2.0000
	s = (s-a)*(s-b)*(s-c)*(s-d)
	s = math.sqrt(s)
	print "%.2f" % s 
