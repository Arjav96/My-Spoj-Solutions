#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
 
int main() {
	//printf("1\n");
	vector<pair <long long ,long long> > V;
	long n,count=1;
	long long x,y,x1,y1;
	scanf("%ld",&n);
	//printf("1\n");
	while(n--){
		scanf("%lld%lld",&x,&y);
		V.push_back(make_pair(x,y));
	}
	sort(V.rbegin(),V.rend());
	
	//printf("1\n");
	for(int i=0;i<int(V.size());++i){
		 if(count == 1){
		 	x1 = V[0].first;
		 	y1 = V[0].second;
		 }
		 if(V[i].first != x1 && V[i].second > y1){
		 	count++;
		 	x1 = V[i].first;
		 	y1 = V[i].second;
		 	//cout << x1 << " " << y1 <<"\n";
		 }
	}
	
	printf("%ld\n",count);
	return 0;
} 
