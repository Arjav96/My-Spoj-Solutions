#include <iostream>
#define MOD 1000000007
using namespace std;
 
long long modulo(long long b){
	long long x=1,y=2;
	while(b>0){
		if(b&1)
			x = (x*y)%MOD;
		y = (y*y)%MOD;	//squaring the base
		b/=2;
	}
	return x % MOD;	
}
 
int main() {
	long n,t;
	scanf("%ld",&t);
	for(long i=0;i<t;++i){
		scanf("%ld",&n);
		if(n==1){
			printf("Case %ld: 1\n",i+1);
		}
		else{
		printf("Case %ld: %lld\n",i+1,((n+1)*modulo(n-2))%MOD);
		}
	}
	return 0;
} 
