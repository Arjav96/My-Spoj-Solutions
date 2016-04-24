#include<stdio.h>
#include<stdlib.h>
int main()
{
 int TIME;
 scanf("%d",&TIME);
 while(TIME--)
 {
  int key;
  scanf("%d",&key);
  char *ENC,temp,ch;
  ENC=(char *)malloc(100001*sizeof(char));
  scanf("%s",ENC);
  int i=0;
  if(key<=25)
  {
   while(ENC[i]!=0)
   {
    ch=ENC[i];
    if(ch>=97&&ch<=122)
    {
     ch=ch-97;
     ch=(ch+key)%26;
     ch=ch+97;
    }
    else if(ch>=65&&ch<=90)
    {
     ch=ch-65;
     ch=(ch+key)%26;
     ch+=65;
    }
    else
     ch=32;
    ENC[i]=ch;
    i++;
   }
  }
  else
  {
   while(ENC[i]!=0)
   {
    ch=ENC[i];
    if(ch>=97&&ch<=122)
    {
     ch=ch-97;
     ch=(ch+key)%26;
     ch=ch+65;
    }
    else if(ch>=65&&ch<=90)
    {
     ch=ch-65;
     ch=(ch+key)%26;
     ch+=97;
    }
    else
     ch=32;
    ENC[i]=ch;
    i++;
   }
  }
  printf("%s\n",ENC);
 }
 return 0;
}
 
