#include <cstdio>
#include<iostream>
using namespace std;
#define i64 long long
 
i64 n,p;
 
void solve()
{
i64 pb2=p/2,pb;
i64 ans=0;
i64 tn;
i64 d=0;
if(n>=pb2)
{
n=pb2;
}
else
{
if(n!=1 && n!=0)
{
d=2*(pb2-n)/(n*(n-1));
}
}
//printf("%lld\n",d);
//d = (i64)d;
pb = p - (n*(2 + (n-1)*d))/2;
ans += pb;
 
i64 sumeven = ((n/2)*(2*(1+d) + (n/2 - 1)*2*d))/2;
ans += sumeven;
 
if(n&1)
ans += (1 + (n-1)*d);
if(n==1 || n==0)
{
ans=p;
}
printf("%lld\n",ans);
}
 
int main()
{
int cases;
scanf("%d",&cases);
while(cases--)
{
scanf("%lld %lld",&p,&n);
solve();
}
return 0;
}
 
