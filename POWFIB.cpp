#include <bits/stdc++.h>
//#define MOD 1000000007
using namespace std;
 
long long int MOD = 1000000007;
 
void multiply(long long int F[2][2], long long int M[2][2]);
void power(long long int F[2][2], long int n);
 
/* function that returns nth Fibonacci number */
long long int fib(long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
/* Optimized version of power() */
void power(long long int F[2][2], long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  (F[0][0]*M[0][0] % MOD + F[0][1]*M[1][0] % MOD) % MOD;
  long long int y =  (F[0][0]*M[0][1] %MOD + F[0][1]*M[1][1] % MOD) % MOD;
  long long int z =  (F[1][0]*M[0][0] % MOD + F[1][1]*M[1][0] % MOD) % MOD;
  long long int w =  (F[1][0]*M[0][1] % MOD + F[1][1]*M[1][1] % MOD) % MOD;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
long long int nonfib(long int n){
long long int a=1,b=2,c=3,ans;
while(n>0){
a=b;
b=c;
c=a+b;
n -= (c-b-1);
}
n += (c-b-1);
ans = n + b;
return ans;
}
 
long long int modulo(long long int a,long long int b,long long int c){
	long long int x = 1;
	long long int y = a;
	while (b > 0){
		if (b % 2 == 1){
			x = (x * y) % c;
        }
        y = (y * y) % c;  // squaring the base
        b /= 2;
    }    	
	return x % c;
}
 
int main() {
	long int t,n;
	long long int a,b,ans;
	cin>>t;
	while(t--){
	cin>>n;
	//a = nonfib(n);
	//cout << a <<"\n";
	//b = fib(n) % MOD;
	//cout << b<< "\n";
	ans = modulo(nonfib(n),fib(n) % MOD,MOD);
	cout << /*a << "\n"<< b << "\n" << */ans <<"\n";
	}
	return 0;
} 
