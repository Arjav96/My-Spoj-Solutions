import os
import sys
 
t = int(raw_input())
for i in range(t):
	n , k = map(int ,sys.stdin.readline().split(' '))
	n-=1
	k-=1
	x = n - k
	if n == k or k ==0:
		tmp = 1
	elif k == 1:
		tmp = n
	elif x > k:
		j = 1
		tmp = 1
		while j <= k:
			if n%j == 0:
				tmp*=(int(n/j))
			elif tmp%j == 0:
				tmp = n*(int(tmp/j))
			else:
				tmp = int((n*tmp)/j)
			j+=1
			n-=1
	elif x <= k:
		j = 1
		tmp = 1
		while j <= x:
			if n%j == 0:
				tmp*=(int(n/j))
			elif tmp%j == 0:
				tmp = n*(int(tmp/j))
			else:
				tmp = int((n*tmp)/j)
			j+=1
			n-=1
 
	print tmp 
