#include <iostream>
#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main() {
	vector< pair<long,long> > V;
	int t;
	long n,start,end,cnt,i;
	scanf("%d",&t);
	while(t--){
		scanf("%ld",&n);
		for(int i=0;i<n;++i){
			scanf("%ld%ld",&start,&end);
			V.push_back(make_pair(end,start));
		}
		sort(V.begin(),V.end());
		i=0;
		cnt = 1;
		for(long j=1;j<n;++j){
			if(V[j].second >= V[i].first){
				cnt++;
				i = j;
			}
			//printf("%ld *\n",cnt);
		}
		printf("%ld\n",cnt);
		V.clear();
	}
	return 0;
} 
