#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
	int t,a[1000010];
	long int n;
	scanf("%d",&t);
	while(t--){
		scanf("%ld",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		long int cnt=1;
		int ans=a[0];
		for(int i=1;i<n;++i){
			if(ans == a[i])
				cnt++;
			else
				cnt--;
			if(cnt == 0){
				ans = a[i];
				cnt = 1;
			}
		}
		// Verify
		long int check=0;
		for(int i=0;i<n;++i){
			if(a[i] == ans)
				check++;
		}
		if(check > n/2)
			printf("YES %d\n",ans);
		else
			printf("NO\n");
	}
	return 0;
} 
