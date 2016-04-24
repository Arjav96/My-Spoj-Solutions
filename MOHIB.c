//Mohib and series.
 
#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int x,avg,n,sum;
scanf("%d %d",&x,&avg);
n=avg-x+1;
sum=(n*avg)-x;
 
if(!(n-2>0))
printf("%d\n",sum);
else
printf("%d\n",sum-((n-2)*(n-1)/2));
}
return 0;
} 
