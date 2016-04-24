/EULER TOLIENT FUNCTION
/*
In number theory, the totient of a positive integer n is defined to be the number of positive integers less than or equal to n that are coprime to n.
*/
 
#include <iostream> 
#include<stdio.h> 
using namespace std;
 
int ETF ( int n ) { 
int result = n ; 
for ( int i = 2 ; i * i <= n ; ++ i )
 if ( n % i == 0 ) 
{ while ( n % i == 0 ) n /= i ; 
result -= result / i ; 
}
 if ( n > 1 )
 result -= result / n ; 
return result ;
}
 int main() {
 int t,n; 
scanf("%d",&t); 
while(t--) { 
scanf("%d",&n);
 printf("%d\n",ETF(n)); 
}
 return 0;
 }  
