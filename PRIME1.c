#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int primes[3500], len = 0;
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
	int i;		
	for (i = 2; i < 32000; ++i) {
		if (isPrime(i)) {
			primes[len++] = i;
		}
	}
}
 
int preProcess(long x) {
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
	unsigned long f, s;
	generatePrime();
	scanf("%d", &t);
	while (t--) {
		scanf("%lu%lu", &f, &s);
		if (f == 1) {
			++f;
		}
		while (f <= s) {
			if(preProcess(f)) {
				printf("%lu\n", f);
			}
			++f;
		}
		printf("\n");
	}
	return 0;
} 
