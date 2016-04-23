#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t);
#define MOD 1000000007
 
int main(){
	int t,n,c,c1;
	long loc[100003],minl,maxl,mid,l,maxmid;
	S(t);
	while(t--){
		maxmid = -1;
		S(n);S(c);c1=c;
		for(int i=0;i<n;++i){
			S(loc[i]);
		}
		sort(loc,loc+n);
		minl = loc[0]; maxl = loc[n-1];
		while(minl < maxl){
			c1=c-1;
			mid = minl + (maxl - minl)/2;
			l = loc[0]; 
			for(int i=1;i<n;++i){
				if((loc[i] - l) >= mid){
					c1--;
					l = loc[i];
				}
				if(!c1){
					break;
				}
			}
			if(!c1){
				minl = mid + 1;
				if(mid > maxmid) maxmid = mid;
			}
			else{
				maxl = mid;
			}
		}
		printf("%ld\n",maxmid);
	}
} 
