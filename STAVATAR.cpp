#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int main()
{
    long n;
    scanf("%ld",&n);
    char s1[1000010],s2[1000010];
 
    //getchar();
    //scanf("%[^\n]s",s1);
    //getchar();
    //scanf(" %[^\n]s",s2);
    //getchar();
    //scanf("%[^\n]%*c",s1);
    //scanf("%[^\n]%*c",s2);
 
    getchar();
    for(long i=0; i<n; i++)
    {
        s1[i] = getchar();
    }
    s1[n]='\0';
    getchar();
    for(long i=0; i<n; i++)
    {
        s2[i] = getchar();
    }
    s2[n]='\0';
 
    long m;
    long L,R;
    long cnt[1000010];
    scanf("%ld",&m);
    for(long i = 0; i < m; ++i){
        scanf("%ld%ld",&L,&R);
        //cout<<L<<" "<<R<<"\n";
        ++cnt[L];
        --cnt[R+1];
    }
 
    long long sum=0;
    for(long i=0;i<n;i++)
    {
        sum += cnt[i];
        if(sum % 2 != 0)
        {
            char t;
            t = s1[i];
            s1[i] = s2[i];
            s2[i] = t;
            //cout<<s1[i]<<"!"<<s2[i]<<"#";
        }
    }
    printf("%s\n%s\n",s1,s2);
    //cout << s1 <<"\n"<<s2 <<"\n";
    return 0;
    } 
