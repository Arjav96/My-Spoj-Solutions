#include<stdio.h>
void quicksort(long int [],int ,int );
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int N,K;
  scanf("%d%d",&N,&K);
  long int TOTAL[N];
  int i,j;
  for(i=0;i<N;i++)
   scanf("%ld",&TOTAL[i]);
  quicksort(TOTAL,0,N-1);
  long int DIFF[N-K+1];
  for(i=0,j=K-1;i<(N-K+1);i++,j++)
  {
   DIFF[i]=TOTAL[i]-TOTAL[j];
  }
  quicksort(DIFF,0,N-K);
  printf("%ld\n",DIFF[N-K]);
 }
 return 0;
}
void quicksort(long int x[],int first,int last){
    int pivot,j,temp,i;
 
     if(first<last){
         pivot=first;
         i=first;
         j=last;
 
         while(i<j)
         {
             while(x[i]>=x[pivot]&&i<last)
                 i++;
             while(x[j]<x[pivot])
                 j--;
             if(i<j)
             {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
             }
         }
 
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);
 
    }
} 
