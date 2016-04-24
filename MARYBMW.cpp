#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t);
#define MAX 50000
 
int id[MAX+3],n,e;
pair<long long, pair<int,int> > P[MAX+3];
pair<long long , pair<int ,int> > G[MAX+3];
 
void init(){
	for(int i=0;i<(MAX+3);++i){
		id[i] = i;
	}
}
 
int root(int x){
	while(id[x]!=x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}
 
void union1(int x,int y){
	id[root(x)] = id[root(y)];
}
 
long long kruskal(pair<long long ,pair<int ,int > > P[]){
	int x,y;
	long long speed;
	int cnt=0;
	for(int i=e-1;i>=0;--i){
		x = P[i].second.first;
		y = P[i].second.second;
		speed = P[i].first;
		if(root(x) != root(y)){
			//G[cnt++] = make_pair(speed, make_pair(x, y));
			//printf("#%lld %d %d#\n",speed,x,y);
			union1(x, y);
			if(root(1) == root(n)){
				return speed;
			}
		}
	}
	return -1;
}
 
int main(){
	int t,x,y;long long v;
	S(t);
	while(t--){
		init();
		S(n);S(e);
		for(int i=0;i<e;++i){
			S(x);S(y);scanf("%lld",&v);	
			P[i] = make_pair(v, make_pair(x, y));
		}
		sort(P, P+e);
		printf("%lld\n",kruskal(P));
		
	}
} 
