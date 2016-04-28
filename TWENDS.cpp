#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t)
#define MAX 1000
 
int dp[MAX+3][MAX+3];
int arr[MAX+3];
int compute(int low,int high){
	if(low > high) return 0; 
	if(dp[low][high] != -1) return dp[low][high];
	int l = arr[low] + ((arr[low+1] >= arr[high]) ? compute(low+2,high) : compute(low+1,high-1));
	int r = arr[high] + ((arr[low] >= arr[high-1]) ? compute(low+1,high-1) : compute(low,high-2));
	return dp[low][high] = max(l, r);
}
 
int main(){
	int n,sum=0;
	for(int i=1;;++i){
		sum = 0;
		S(n);
		if(n == 0) break;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;++i){
			S(arr[i]);
			sum += arr[i];
		}
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",i,(2 * compute(0,n-1)) - sum);
	}
} 
