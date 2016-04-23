//Acode simple dp,or fibonacci series.
#include<bits/stdc++.h>
using namespace std;
int main()
{
 while(1)
 {
  char s[5010];
  scanf("%s",s);
  if(s[0]=='0')
  	break;
 unsigned long long int dp[5010];
 long long int len=strlen(s);
 memset(dp,0,5010);
 dp[0]=1;
 long long int x,i;
 for(i=1;i<=len-1;i++)
 {
   x=(s[i-1]-'0')*10+(s[i]-'0');
       if(s[i]-'0')
       dp[i]=dp[i-1];
       if(x>=10 && x<=26)
       dp[i]+=dp[(i-2)<0?0:i-2];
 }
 printf("%llu\n",dp[len-1]);
 }
 return 0;
}
 
