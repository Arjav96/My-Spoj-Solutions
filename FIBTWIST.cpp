/*
MATRIX EXPONENTATION
*/
 
//Special fibonacci seq: f(n) = f(n-1) + f(n-2) + (n-1), f(0)=0,f(1)=1.....find f(n)%m
 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lli long long int
 
lli matexpo(lli n,lli m){
lli r[][2]={{1,0},{0,1}};
lli fib[][2]={{1,1},{1,0}};
lli temp[2][2];
 
while(n){
 
if(n&1){
memset(temp,0,sizeof temp);
for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
for(int k=0;k<2;k++)
temp[i][j]+=(r[i][k]*fib[k][j])%m;
for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
r[i][j]=temp[i][j];
}
 
memset(temp,0,sizeof temp);
for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
for(int k=0;k<2;k++)
temp[i][j]+=(fib[i][k]*fib[k][j])%m;
for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
fib[i][j]=temp[i][j];
n/=2;
}
return r[0][0];
}
 
int main(){
 
int tc;
lli n,m,ans;
scanf("%d",&tc);
while(tc--){
scanf("%lld%lld",&n,&m);
ans=(2*(matexpo(n+1,m)-1)-n)%m;
if(ans<0)
ans+=m;
printf("%lld\n",ans);
}
} 
