#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long num;
        scanf("%lld",&num);
        long long ans;
        ans=192+(num-1)*250;
        printf("%lld\n",ans);
    }
    return 0;
} 
