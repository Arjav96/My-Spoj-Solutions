#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
 
int main() {
	multiset<long int> s;
	multiset<long int>::iterator it;
	int days;
	long int k,m;
	long long int diff=0; 
	scanf("%d",&days);
	while(days--){
		scanf("%ld",&k);
		while(k--){
			scanf("%ld",&m);
			s.insert(m);
		}
		
		it = s.end();
		diff += (*(--it) - *(s.begin()));
		//cout<<diff<<"\n";
		s.erase(s.begin());
		s.erase(it);
	}
	printf("%lld\n",diff);
	
	return 0;
} 
