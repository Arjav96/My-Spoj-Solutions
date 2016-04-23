#include <iostream>
#include <cstdio>
using namespace std;
 
int count_1(long long a){
	int count=0;
	while(a>0){
		a = a & (a-1);
		count++;
	}
	//printf("#%d\n",count);
	return count;
}
 
int main() {
	int t;
	long long n;
	int k;
	scanf("%d",&t);
	while(t--){
		int cnt1=0,cnt2=0;
		scanf("%lld%d",&n,&k);
		long long int n2 = n,n3 = n - 1,n4 = n - 1;
		if( k == 0){
			printf("-1\n");
			continue;
		}
		if( k == 1){
			printf("1\n");
			continue;
		}
		while(n2 > 0){
			n2 >>= 1;
			//cout<<n<<endl;
			cnt1++;
		}
		
		while(n4 > 0){
			n4 >>= 1;
			cnt2++;
		}
		
		if((cnt1-1) <= k){
			//printf("*%d\n",count_1(n));
			printf("%lld\n",n-1);
			continue;
		}
		
		if(count_1(n-1) <= k){
			printf("%lld\n",n-1);
			continue;
		}
		int j=1,x=0;
		long long ans = 0,prev = 0;
		while(j <= cnt2){
			n3 >>= (cnt2 - j);
			if( x == 0)
				n3 <<= (cnt2 - j);
			else{
				n3 += x;
				n3 <<= (cnt2 - j);
			}
			n3++;
			if(n3 > n){
				n3 = ans;
				j++;
				x = 1;
				continue;
			}	
			if(count_1(n3) > k){
				printf("%lld\n",ans);
				break;
			}
			j++;
			x = 1;
			ans = n3;
		}
		/*
		for(long long int i=n-1;i>=1;i-=2){
			if(count_1(i) <= k){
				printf("%lld\n",i);
				flag=0;
				break;
			}
		}
		if(flag)
			printf("-1\n");
		*/
	}
	return 0;
}
