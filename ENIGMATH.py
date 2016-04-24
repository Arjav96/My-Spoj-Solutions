def gcd(a , b):
	if b == 0:
		return a
	return gcd( b , a % b)
 
t = int(raw_input())
 
for i in xrange(t):
 
	num = map(int , raw_input().split())
	c = gcd(num[0] , num[1])
	print num[1]/c , num[0]/c 
