#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t)
#define MAX 2000
 
int dp[MAX+3][MAX+3];
int arr[MAX+3];
int compute(int low,int high,int age){
	if(low == high) return dp[low][high] = age*arr[low]; 
	if(dp[low][high] != -1) return dp[low][high];
	return dp[low][high] = max(compute(low+1,high,age+1) + age*arr[low], compute(low,high-1,age+1) + arr[high]*age);
}
 
int main(){
	int n;
	S(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;++i){
		S(arr[i]);
	}
	P(compute(0,n-1,1));
} 
