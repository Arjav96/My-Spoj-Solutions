# fibo series starting from 2nd (1).
 
a = []
a.append(1)
a.append(2)
for i in range(2,45):
	a.append(a[i-1] + a[i-2])
 
for i in range(int(raw_input())):
	x = int(raw_input())
	print a[x]
	#print a 
 
