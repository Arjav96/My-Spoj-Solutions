import math
 
def modulo(expo):
	x,y = 1,10
	while expo > 0 :
		if expo & 1:
			x = (x * y) % 1000000007
		y = (y * y) % 1000000007
		expo /= 2
	return x % 1000000007
 
t = int(raw_input())
for i in range (t):
	n = int(raw_input())
	mod = modulo(n-1) - 1
	if mod < 0 :
		mod += 1000000007
	m = ((10 * mod * 111111112) - (n - 1)) * 111111112
	if m < 0 :
		while m < 0 :
			m += 1000000007
	ans = ((6 * n) + (50 * m)) % 1000000007
	print ans
"""
y=1
while (9 * y) % 1000000007 != 1 :
	y += 1
print y % 1000000007
""" 
