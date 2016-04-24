#include<bits/stdc++.h>
using namespace std;
#define MAX 100003
long long int bit1[MAX+1],bit2[MAX+1];
 
void update(long long int bit[],int i,long long int val){	
	while(i <= MAX){
		bit[i] += val;
		i += (i&-i);
	}
}
 
long long int query(long long int bit[],int i){
	long long int sum=0;
	while(i > 0){
		sum += bit[i];
		i -= (i&-i);
	}
	return sum;
}
 
void rangeupdate(int p,int q,long long int v){
	update(bit1,p,v);
	update(bit1,q+1,-v);
	update(bit2,p,v*(p-1));
	update(bit2,q+1,-v*q);
}
 
long long int rangequery_point(int x){
	return (query(bit1, x) * x - query(bit2, x));	
}
 
long long int rangequery(int p,int q){
	return (rangequery_point(q) - rangequery_point(p-1));
}
 
int main(){
	int t,n,c,x,p,q;
	long long int v;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&c);
		memset(bit1,0,sizeof(bit1));
		memset(bit2,0,sizeof(bit2));
		for(int i=1;i<=c;++i){
			scanf("%d",&x);
			if(x==0){
				scanf("%d%d%lld",&p,&q,&v);
				rangeupdate(p,q,v);
			}
			else if(x==1){
				scanf("%d%d",&p,&q);
				printf("%lld\n",rangequery(p,q));
			}
		}
	}
} 
