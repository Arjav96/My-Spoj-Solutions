#include<stdio.h>
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",(n*(3*n+1)/2)%1000007);   
    }
    return 0;
} 
