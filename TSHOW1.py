# finding xth num consisting of only '5' or '6'.
 
d = { 1:'5', 0: '6'}
 
for i in range(input()):
	x = input()
	s = ""
	while x:
		x,r = divmod(x,2)
		if r == 0:
			x -= 1
		s = d[r] + s		# append from front
	print s 
