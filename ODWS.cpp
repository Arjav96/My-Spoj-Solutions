#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
 
int main(){
	int t;
	scanf("%d",&t);
	char s1[105],s2[105];
	for(int cases = 1;cases <= t; cases++){
		scanf("%s%s",s1,s2);
		int len = strlen(s1);
		long long ans=0;
		for(int i = 0; i < len; ++i){
			ans = (((s2[i] - 'a') - (s1[i] - 'a')) + ans * 26) % MOD ;
		}
		printf("Case %d: %lld\n",cases,(ans - 1 + MOD) % MOD);
	}
	return 0;
} 
