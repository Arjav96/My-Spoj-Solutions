#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t);
 
struct trie{
	int next[26];
	int flag;
}node[500005];
 
int allocated;
char str[25005][21],ss[21];
 
void insert(char s[],int len){
	int root = 0;
	for(int i=0;i < len;++i){
		if(node[root].next[s[i] - 'a'] == 0){
			node[root].next[s[i] - 'a'] = allocated;	
			root = allocated;
			allocated++;
		}
		else{
			root = node[root].next[s[i] - 'a'];
		}	
	}
	node[root].flag = 1;
}
 
void dfs(char *s,int len,int root){
	if(node[root].flag){
		printf("%s\n",s);
	}
	for(int i=0;i<26;++i){
		if(node[root].next[i]){
			s[len + 1] = i + 'a';
			s[len + 2] = '\0';
			dfs(s,len+1,node[root].next[i]);
		}
	}
}
 
void check(char *s,int len){
	int root = 0;
	for(int i=0;i < len;++i){
		if(node[root].next[s[i] - 'a'] == 0){
			printf("No match.\n");
			return;
		}
		else{
			root = node[root].next[s[i] - 'a'];
		}	
	}
	bool ch = false;
	for(int i=0;i<26;++i){
		if(node[root].next[i]){
			s[len] = i + 'a';
			s[len + 1] = '\0';
			dfs(s,len,node[root].next[i]);
			ch = true;
		}
	}
	if(!ch){
		printf("No match.\n");
		return;
	}
}
 
int main(){
		int t,n,k;
		memset(node,0,sizeof(node));
		allocated = 1;
		S(n);
		for(int i=0;i<n;++i){
			scanf("%s",str[i]);
			insert(str[i],strlen(str[i]));
		}
		S(k);
		for(int i=0;i<k;++i){
			scanf("%s",ss);
			printf("Case #%d:\n",i+1);
			check(ss, strlen(ss));
		}
		
} 
