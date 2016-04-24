#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int t,i,n,ans;
int x[1001],y[1001];
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d ",&x[i]);
}
for(i=0;i<n;i++)
{
scanf("%d ",&y[i]);
}
 sort(x, x + n);
 sort(y, y + n);
ans=0;
for(i=0;i<n;i++)
{
ans=ans+x[i]*y[i];
}
 
printf("%d\n",ans);
}
return(0);
}
 
