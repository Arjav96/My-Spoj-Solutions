#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define lim 99999999
#define LL long long
vector<bool> b((lim>>1)+100);
LL p[5000100];
LL prime()
{
 LL i,j;
 for(i=3;i<=9999;i+=2)
 {
  if(b[(i-3)>>1]==0)
  {
   for(j=i*i;j<lim;j+=2*i)
   {
     b[(j-3)>>1]=1;
   }
  }
 }
  LL count=0,x=1;
  for(i=0;2*i<lim;++i)
   if(!b[i])
   {
    x++;
    if(x%100==1)
    p[count++]=2*i+3;
   }
   return count;
}
int main()
{
     
      LL count,i;
       count=prime();
      printf("2\n");
      for(i=0;i<count;i++)
      printf("%lld\n",p[i]);
 return 0;
} 
