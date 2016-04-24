 
#include<iostream>
#include<stdio.h>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
#define mod 1000000007
#define MAX 50000
#define ll long long int
map<ll,ll> prime,div;
ll i,j,s,res,k,ans,x;
vector<ll> pr;
 
 
int main()
{
	for(i=3;i<sqrt(MAX+1);i+=2)
	{
		if(prime[i/2]==0)
		{
			for(j=i*i;j<MAX+1;j+=2*i)
			{
				prime[j/2]=1;
			}
		}
	}
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		x=0;
		scanf("%lld",&n);
		ans=1;
		k=2;
		while(n/k!=0)
		{
			x+=n/k; k*=2;
		}
		ans*=(x+1);
		for(i=3;i<=n;i+=2)
		{
			if(prime[i/2]==0)
			{
			x=0;
			k=i;
			while(n/k>0)
			{
				x+=n/k;
				k*=i;
			}
			ans*=(x+1);
			ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
 
