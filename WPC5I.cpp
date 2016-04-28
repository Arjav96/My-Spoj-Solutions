#include<bits/stdc++.h>
#define scan(x) scanf("%i",&x)
 
int prime[4900],prime_index = 1,number[47001]={0};
 
int main()
{
    int i,j,k,a,b,t,count1,count2,temp;    long long pro;
 
    prime[1] = 2;
 
    for(i = 3;    i <= 217;     i += 2)
    {
        if(number[i] == 0)
        {
            prime[++prime_index] = i;
            for(j = i*i, k = 2*i;    j <= 47000;    j += k)
                number[j] = 1;
        }
    }
 
    for(    ;   i <= 47000;  i += 2)
        if( number[i] == 0)
            prime[++prime_index] = i;
 
    scan(t);
 
    while(t--)
    {
        scan(a);
        scan(b);
 
        pro = i = 1;
 
        while(i <= prime_index && (a != 1 || b != 1))
        {
            count1 = count2 = 0;
 
            while(a%prime[i] == 0)
            {
                a /= prime[i];
                count1++;
            }
 
            while(b%prime[i] == 0)
            {
                b /= prime[i];
                count2++;
            }
 
            if(count1 != count2)
            {
                temp = (count1 > count2) ? count1 : count2;
 
                while(temp)
                {
                    pro *= prime[i];
                    temp--;
                }
            }
 
            i++;
        }
 
        if(a != b)
        {
            pro *= a;
            pro *= b;
        }
 
        printf("%lli\n",pro);
    }
 
    return 0;
} 
