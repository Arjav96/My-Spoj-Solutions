#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char K[1000002];
int flag;
 
void find_palin()
{
 
int len,i,tmp,t,tmp1;
len = strlen(K);
flag = 1;
 
for(i=0; i<len; i++)
{
if(K[i] != '9')
{
flag = 0;
break;
}
}
 
if(flag == 1)
{
K[0] = '1';
for(i=1; i<len; i++)
K[i] = '0';
K[len] = '1';
K[len+1] = '\0';
return ;
}
 
 
for(i=0; i<len/2; i++)
{
if(K[i] < K[len-i-1])
flag = -1;
else if(K[i] > K[len-i-1])
flag = 1;
K[len-i-1] = K[i];
}
 
if(flag == -1 || flag==0)
{
t = 0;
if(len%2 == 0)
tmp1 = len/2-1;
else
tmp1 = len/2;
while(K[tmp1-t] == '9')
{
K[tmp1-t] = '0';
K[len-1-tmp1+t] = '0';
t++;
}
K[tmp1-t] ++;
K[len-1-tmp1+t] = K[tmp1-t];
}
 
return ;
}
 
 
int main()
{
int t,i;
scanf("%d\n",&t);
 
for(i=0; i<t; i++)
{
gets(K);
find_palin();
printf("%s\n",K);
}
return 0;
} 
