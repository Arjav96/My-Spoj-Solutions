#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long p[n+10];
		for(int i=0;i<n;++i){
			scanf("%lld",&p[i]);
		}
		long long k;
		long long sum = 0;
		for(int i=0;i<n;++i){
			scanf("%lld",&k);
			p[i] %= (k+1);
			sum ^= p[i];
		}
		if(sum)
			printf("Amit\n");
		else
		printf("Mishra\n");
	}
	return 0;
} 
