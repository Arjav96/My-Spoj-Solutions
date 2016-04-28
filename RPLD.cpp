#include <iostream>
#include <utility>
#include <set>
#include <cstdio>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	for(int a=0;a<t;++a){
		long int n,r,i,c;
		set< pair<int,int> > S;
		scanf("%ld%ld",&n,&r);
		for(int j=0;j<r;++j){
			scanf("%ld%ld",&i,&c);
			S.insert(make_pair(i,c));
		}
		if(S.size() == r)
			printf("Scenario #%d: possible\n",a + 1);
		else
			printf("Scenario #%d: impossible\n",a + 1);
	}
	return 0;
} 
