// K**t * N <= M.
 
#include<stdio.h>
 
int main()
{
    long long n,k,m,pro;    int t,i;
 
    scanf("%i",&t);
 
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&k,&m);
 
        i=0;
 
       if(k <= m/n)
       {
           i++;
 
           pro = n*k;
 
           while( k <= m/pro)
           {
               i++;
               pro *= k;
           }
 
       }
 
        printf("%i\n",i);
    }
    return 0;
}
 
