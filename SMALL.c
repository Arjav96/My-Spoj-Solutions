 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
# define MOD 1000000007
 
int primes[1000], new_primes[1500], len = 0;
int isPrime(int number) {
	if (number == 2) {
		return 1;
	}
	if (number % 2 == 0) {
		return 0;
	}
	int i;
	int squareRoot = sqrt(number);
	for (i = 3; i <= squareRoot; i += 2) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}
 
void generatePrime() {
	int i;		
	for (i = 2; i < 100; ++i) {
		if (isPrime(i)) {
			primes[len++] = i;
		}
	}
}
 
int preProcess(int x) {
	int i, last = sqrt(x);
	for (i = 0; i < len && primes[i] <= last; ++i) {
		if (!(x%primes[i])) {
			return 0;
		}
	}
	return 1;
}
 
long long mul( long long a,long long b){
	long long r = a*b - floor(1.0*a*b/MOD)*MOD;
	return r < 0 ? r + MOD : r >= MOD ? r - MOD : r;
}
 
 
 
 
 
int main() {
	int t;
	int n ,start,i,j,k;
	long long ans,len2;
	generatePrime();
	scanf("%d", &t);
	while (t--) {
		start = 2;
		ans = 1;
 
		scanf("%d", &n);
		i = 0;
		while ( start<= n) {
			if(preProcess(start)) {
				new_primes[i++] = start;
			}
			++start;
		}
		j = i;
		//len2 = j;
		k = 0;
		while(j>0){len2 = 1;
			if(new_primes[k] <= sqrt(n)){
				 while(new_primes[k]*len2 <= n)
					len2 *=new_primes[k];
				ans = mul(ans, len2);
				
			}else {
				ans = mul(ans , new_primes[k]) ;
				
			}
			k++;
			j--;
		}
		
 
		printf("%llu",ans);
		printf("\n");
	//	for(i=0;i<len2;i++)
	//		printf("%d ",new_primes[i]);
	//	printf("\n");
	//	for(i=0;i<len;i++)
	//		printf("%d ",primes[i]);
 
	}
	return 0;
} 
