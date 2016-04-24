//two strings given: say, abcad and ebada we have to find characters present in both as a subsequence, i.e., aabd in alphabetic order. 
 
	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	#include <iostream>
	
	using namespace std;
	
	const int MAXN=1010;
	
	char a[MAXN],b[MAXN];
	int cnt[26];
	
	void solve()
	{
	memset(cnt,0,sizeof(cnt));
	for(int i=0;a[i];++i)
	cnt[a[i]-'a']++;
	sort(b,b+strlen(b));
	for(int i=0;b[i];++i)
	if(cnt[b[i]-'a'])printf("%c",b[i]),cnt[b[i]-'a']--;
	printf("\n");
	}
	int main()
	{
	while(scanf("%s%s",a,b)!=EOF)
	solve();
	return 0;
	} 
