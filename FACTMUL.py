 
# Obtaining 1!*2!*......*n!%c
 
c = 109546051211
ans = 1
prev = 1
n = int(raw_input())
for i in range(2,n+1):
	cur = (prev*i)%c
	ans = ((ans%c)*cur)%c
	if ans == 0:
		break
	prev = cur
print ans 
