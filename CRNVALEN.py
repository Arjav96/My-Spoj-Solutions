"""
count the no of double dating girls : given no of girls n and no of double dating in rest n-1 girls which the other girl tells.
 
""" 
 
def solve(n, girls):
	d = max(girls)
	if d >= n:
		return -1
	temp = 0
	for i in girls:
		if i is d - 1:
			temp += 1
		elif i is not d:
			return -1
	if temp is d:
		return d
	if temp is 0:
		return d + 1
	return -1
 
 
for _ in xrange(int(raw_input())):
	print solve(int(raw_input()), map(int, raw_input().split()))  
