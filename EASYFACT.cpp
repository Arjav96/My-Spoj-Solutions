/*
# For each prime p , the power of p in n! is given by : power(p) = n/p + n/p^2 + n/p^3 ....until we get a zero
 
# Total possible waysof representing n! as sum of consecutive integers are,... for each odd prime p :((power(p1)+1) * (power(p2)+1) * .... (power(pk)+1) - 1) , assuming there are k prime numbers occuring in n!.
*/
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 99999999
#define ll long long int
using namespace std;
 
ll i,j,k,ans,x;
ll prime[5761500], len = 0 ;
 
//sieve of atkin
vector<bool> sieve(MAX,true); //LEN is length of sieve here its little less than 10^8
 
void find_primes () {
	long long i , j , i2 ;
	for( i = 3 ; i <= 9999 ; i += 2 ) { //9999 is sqrt(MAX)
		while( sieve[i] == false )
			i += 2;
		j = i*(i-2);
		i2 = i << 1 ;
		while( ( j = i2 + j ) <= MAX )
			sieve[j] = false;
	}
	
	for( i = 3 ; i <= MAX ; i += 2 ){
		if( sieve[i] ){
			prime [len++] = i ;
		}
		//cout << len <<"\n";			//5761454
	}
}
 
ll modulo (ll a,ll b,ll c){
	ll x = 1, y = a;
	while(b > 0){
		if(b & 1){
			x = (x * y) % c;
		}
		y = (y * y) % c;
		b /= 2;
	}
	return x % c;
}
 
inline void fastRead_int(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
 
inline void fastRead_long(ll *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
 
int main()
{
	find_primes();
	int t;
	//scanf("%d",&t);
	fastRead_int(&t);
	while(t--)
	{
		ll n,m;
		x=0;
		fastRead_long(&n);
		fastRead_long(&m);
		//scanf("%lld %lld",&n,&m);
		ans=1;
		if(n==0||n==1||n==3)
		{
			printf("1\n");
			continue;
		}
	
		else if(n==2)
		{
			printf("0\n");
			continue;
		}
		
		ll i;
		for( i=0 ; i < len && prime[i]*prime[i] <= n ; ++i){
				x=0;
				k=prime[i];
				ll n1 = n;
					while(n1/k > 0){
						x += n1/k;
						n1 /= k;
						//k *= prime[i];
					}
				ans = ((ans % m )*((x+1) % m )) % m;	
		}
		//printf("#%lld\n",i);
		ll j = n/prime[i];//sqrt(n);
		//printf("!%lld\n",j);
		ll index = i;
		ll cnt = 0;
		for( ; j >= 1 && i < len; j--){
			ll check = n/j;
			//cout << "*"<< check <<"\n";
			
			ll low = i,high = ((n/2 + 1) >= len) ? len - 1 : n/2 + 1;		
			while(low != high){
				ll mid = low + (high - low )/2 ;
				if(prime[mid] <= check){	
					low = mid + 1;
				}
				else{
					high = mid;
				}
			}
			//cout << "*"<< low <<"\n";
			cnt = low - index;	
			//cout << "@"<< cnt <<"\n";
			index = low ;
			//cout << "$"<< index <<"\n";
			ans = ((ans % m) * ((modulo(j+1 , cnt , m)) % m)) % m;
		}
		if(((ans - 1) % m) < 0)
			printf("%lld\n",((ans - 1 + m) % m));
		else
			printf("%lld\n",(ans - 1) % m);
	}
	return 0;
} 
