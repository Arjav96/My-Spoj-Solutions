#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,count,shift,max;
    char s[2000];
    scanf("%d",&t);
        getchar();
    while(t--)
    {
        gets(s);
        char p[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int hash[26];
        for(i=0;i<26;i++)
                hash[i]=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]!=' ')
            {
                hash[s[i]-65]++;
            }
        }
        max=0;
        count=0;
        int pos;
        for(i=0;i<26;i++){
                if(hash[i]>max){
                        max=hash[i];
                        pos=i;
                        }
                //printf("%c %d ",i+65,hash[i]);
        }
        for(i=0;i<26;i++)
        {
                if(hash[i]==max)
                        count++;
        }
        int d;
        if(count>1)
                printf("NOT POSSIBLE\n");
        else
        {
                //printf("%d ",pos);
                shift=pos-4;
                if(shift<0)
                        shift=shift+26;
                printf("%d ",shift);
                for(i=0;i<len;i++)
                {
                        if(s[i]!=' ')
                        {
                                d=s[i]-65;
                                d=d-shift;
                                //printf("%d ",d);
                                if(d<0)
                                        d=d+26;
                                s[i]=p[d];
                        }
                        
                }
                printf("%s\n",s);
        }
    }
    return 0;
} 
