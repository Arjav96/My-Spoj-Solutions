#include <stdio.h>
unsigned long long int dp[1010];
int t,n;
unsigned long long int max(unsigned long long int a, unsigned long long int b){
return a > b ? a : b;
}
int main(){
int i, h;
scanf("%d", &t);
for(h=1;h<=t;h++){
scanf("%d",&n);
for(i=0;i<n;i++){
int k;
scanf("%d",&k);
dp[i]=max(k+(i>1?dp[i-2]:0),i>0?dp[i-1]:0);
}
printf("Case %d: %llu\n", h, dp[n-1]);
}
 
return 0;
} 
