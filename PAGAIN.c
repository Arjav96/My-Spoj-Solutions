#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int primes[7000], len = 0;
int isPrime(unsigned long number) {
	if (number == 2) {
		return 1;
	}
	if (number % 2 == 0) {
		return 0;
	}
	int i;
	unsigned long squareRoot = (unsigned long)sqrt(number);
	for (i = 3; i <= squareRoot; i += 2) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}
 
void generatePrime() {
	unsigned long i;		
	for (i = 2; i < 65536; ++i) {
		if (isPrime(i)) {
			primes[len++] = i;
		}
	}
}
 
int preProcess(unsigned long long x) {
	unsigned long i, last = sqrt(x);
	for (i = 0; i < len && primes[i] <= last; ++i) {
		if (!(x%primes[i])) {
			return 0;
		}
	}
	return 1;
}
 
int main() {
	int t;
	unsigned long long f;
	generatePrime();
	scanf("%d", &t);
	while (t--) {
		scanf("%llu", &f);
		
		if(f<5)
			printf("%d",2);
		
		while(1) {
			if(f%2==0)
				f--;
			else
				f-=2;
		
			if(preProcess(f)) {
				printf("%llu\n", f);
				break;		
			}
			
		}
		
	}
	return 0;
} 
