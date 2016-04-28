#include<bits/stdc++.h>
using namespace std;
#define MAX 100003
long int bit[MAX+1];//,bit2[MAX+1];
 
void update(int i,long int val){	
	while(i <= MAX){
		bit[i] += val;
		i += (i&-i);
	}
}
 
long int query(int i){
	long int sum=0;
	while(i > 0){
		sum += bit[i];
		i -= (i&-i);
	}
	return sum;
}
 
void rangeupdate(int p,int q,long int v){
	update(p,v);
	update(q+1,-v);
	
}
 
 
int main(){
	int t,n,u,c,x,p,q;
	long int v;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&u);
		memset(bit,0,sizeof(bit));
		//memset(bit2,0,sizeof(bit2));
		for(int i=1;i<=u;++i){			
				scanf("%d%d%ld",&p,&q,&v);
				rangeupdate(p+1,q+1,v);	
		}
		scanf("%d",&x);
		for(int i=0;i<x;++i){
			scanf("%d",&c);
			printf("%ld\n",query(c+1));
		}
	}
} 
