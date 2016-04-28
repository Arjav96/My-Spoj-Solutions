#include<bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t);
vector <int> bit(100005);
void update_min(int pos,int val,int MAX){
	while(pos <= MAX){
		bit[pos] = min(bit[pos], val);
		pos += (pos&-pos);
	}
}
 
int query_min(int pos){
	int check = INT_MAX;
	while(pos > 0){
		check = min(bit[pos], check);
		pos -= (pos&-pos);
	}
	return check;
}
 
bool cmp(const pair<int, pair<int ,int> > &a, const pair<int, pair<int ,int> > &b){
	return (a.first == b.first ? (a.second.first == b.second.first ? a.second.second < b.second.second : a.second.first < b.second.first) : a.first < b.first );
}
 
int main(){
	int t, n, a, b, c;
	S(t);
	while(t--){
		S(n);
		vector<pair<int,pair<int ,int> > > arr(n);
		for(int i=0;i<n;++i){
			S(arr[i].first);
			S(arr[i].second.first);
			S(arr[i].second.second);
		}
		sort(arr.begin(), arr.end(), cmp);
		/*for(int i=0;i<n;++i){
			P(arr[i].first);
			P(arr[i].second.first);
			P(arr[i].second.second);
		}*/
		fill(bit.begin(),bit.begin() + n + 3,INT_MAX);
		int excel = 0;
		for(int i=0;i<n;++i){
			int cur_check = query_min(arr[i].second.first);
			if(cur_check > arr[i].second.second) excel++;
			update_min(arr[i].second.first, arr[i].second.second, n+10);
		}
		P(excel);
	}
}
 
