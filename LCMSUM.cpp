// find sum of lcm(1,n), lcm(2,n)..... to lcm(n,n)
 
#include<cstdio>
#include<iostream>
#include<cmath>
#define Lim 1000000
 
using namespace std;
long long m[1000010] ;
long long ret[1000010];
 
void cal(){
for(int i = 1 ;i <= Lim ; i++ ) m[i]=i;
for(int i=2 ; i<= Lim ; i++ )
if ( m[i] == i)
for(int j = 2*i ; j <= Lim ; j += i) m[j] -= m[j]/ i ;
for(int i=2 ; i<= Lim ; i++) if ( m[i]==i) m[i] = i-1;
for(int i=1;i <= Lim ; i++) for (int j = i ; j <= Lim ; j += i ) ret[j]+= i*m[i];
}
int main()
{
cal();
int n,t,i, sqt;
long long sum;
for(scanf("%d",&t ) ; t>0 ; t--)
{
scanf("%d",&n);
sum = ( 1 + ret[n] ) * n / 2;
printf("%lld\n",sum);
}
}
 
