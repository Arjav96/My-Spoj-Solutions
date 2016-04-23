#include<bits/stdc++.h>
using namespace std;
#define lim 50000
vector<int>a;
vector<bool>check(lim,false);
void pre()
{
 int i,j;
 for(i=2;i<=34000;i++)
 {
  if(check[i]==false)
  {
   int x=0;
   for(j=i+1;j<=34000;j++)
   {
    if(check[j]==false)
    x++;
    if(x==i)
    {
     check[j]=true;
     x=0;
    }
   }
  }
 }
 for(i=2;i<=34000;i++)
 {
  if(check[i]==false)
  {
   a.push_back(i);
  }
 }
 //printf("%d",a.size());
}
int main()
{
 pre();
 while(1)
 {
  int n;
  scanf("%d",&n);
  if(n==0)
  break;
  printf("%d\n",a[n-1]);
 }
} 
