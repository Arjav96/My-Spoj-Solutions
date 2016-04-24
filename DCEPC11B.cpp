/*** The problem is based on two main concepts 
1 -> Wilsonâs Theorem 
2 -> Inverse modulo (It can be found by Extended Euclidean Algorithm , Fermatâs Little Theorem ,Eulerâs Theorem)
 
here in this problem i have used Fermat's theorem 
 
Wilsonâs Theorem 
 
According to Wilson's Theorem    (n-1)! __ is equiv to__ -1 (mod n) for all prime n;
Now from this we can write :
 
(see image)
***/
 
 
 
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL pow_mod(LL a,LL b,LL m)
{
 LL x=1,y=a;
 while(b>0)
 {
  if(b & 1)
   x=(x*y)%m;
  y=(y*y)%m;
  b>>=1;
 }
 return x;
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  LL n,p,i,result=-1,temp;
  scanf("%lld%lld",&n,&p);
  if(n>=p)
  {
   printf("0\n");
   continue;
  }
  for(i=n+1;i<p;i++)
  {
   temp=pow_mod(i,p-2,p);
   result=(result*temp)%p;
  }
  printf("%lld\n",p+result);
 }
 return 0;
} 
