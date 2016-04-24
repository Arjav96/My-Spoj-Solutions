#include<bits/stdc++.h>
using namespace std;
#define MAX 20003
vector<int> bit(MAX+1),ans(MAX);
 
void update(int i,int val){
	while(i <= MAX){
		bit[i]+=val;
		i += (i&-i);
	}
}
 
int query(int i){
	int sum = 0;
	while(i > 0){
		sum += bit[i];
		i -= (i&-i);
	}
	return sum;
}
int main(){
	int t, n, rot, rem_cards, s, e, mid;
	scanf("%d",&t);
	while(t--){
		bit.clear();
		ans.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			update(i, 1);
		}
		rot = 1; rem_cards = n;  
		for(int i=1;i<=n;++i){
			rot = (rot + i) % rem_cards;
			if(!rot) rot = rem_cards;
			rem_cards--;
			s=1; e=n;
			while(s <= e){
				mid = s + (e-s)/2;
				if(query(mid) >= rot) e = mid-1;
				else s = mid+1;
			}
			
			ans[s] = i;update(s,-1);
		}
		for(int i=1;i<=n;++i){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
 
} 
