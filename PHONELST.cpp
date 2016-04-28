#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t);
#define MOD 1000000007
 
struct trie{
	int next[11];
	int flag;
}node[100005];
 
int allocated;
string str[10005];
 
void insert(string s){
	int root = 0;
	for(int i=0;i < s.length();++i){
		if(node[root].next[s[i] - '0'] == 0){
			node[root].next[s[i] - '0'] = allocated;	
			root = allocated;
			allocated++;
		}
		else{
			root = node[root].next[s[i] - '0'];
		}
		if(i == (s.length() - 1)){
				node[root].flag = 1;
		}		
	}
}
 
bool check(string s){
	int root = node[0].next[s[0] - '0'];
	//P(root);
	for(int i=1;i < s.length();++i){
		//P(s[i] - '0');
		//P(root);
		if(node[root].flag == 1){//&& node[root].next[s[i] - '0']){
			for(int j=0;j < 11;++j){
				if(node[root].next[j])
					return false;
			}
		} 
		root = node[root].next[s[i] - '0'];
	}
	return true;
}
 
int main(){
	int t,n;bool ch;
	S(t);
	while(t--){
		memset(node,0,sizeof(node));
		allocated = 1;
		S(n);
		for(int i=0;i<n;++i){
			cin>>str[i];//scanf("%s",str[i]);
			insert(str[i]);
		}
		for(int i=0;i<n;++i){
			ch = check(str[i]);
			//printf("#\n");
			if(!ch){
				printf("NO\n");
				break;
			}
		}
		if(!ch) continue;
		else{
			printf("YES\n");
		}
	}
} 
