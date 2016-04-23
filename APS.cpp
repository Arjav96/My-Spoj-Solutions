// making of special series a[n] = a[n-1] + f(n) where f(n)is lowest prime factor of n.
 
#include <bits/stdc++.h>
int p[10000009];
long long res[10000009];
void pre()
{
 for(int i=2;i<=10000000;i++)
 {
  if(!p[i])
  {
   for(int j=i+i;j<=10000000;j+=i)
    if(!p[j])
     p[j]=i;
   res[i]=res[i-1]+i;
  }
  else
   res[i]=res[i-1]+p[i];
 }
}
int main()
{
 int t;
 pre();
 scanf("%d",&t);
 while(t--)
 {
  int n;
  scanf("%d",&n);
  printf("%lld\n",res[n]);
 }
 return 0;
}
 
