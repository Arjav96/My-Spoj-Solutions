#include<stdio.h>
#include<string.h>
int main(){
    int t,a,b,c,d,ar[110],i,j,k,l,h;
    char br[110];
    while(scanf("%s",br)!=EOF){
        j=0;
        if(strlen(br)==1 && br[0]==49)
        printf("1\n");
        else{
            for(i=strlen(br)-1;i>=0;i--){
            ar[j]=br[i]-'0';
            j++;
            }
            a=0;
            for(i=0;i<j;i++){
                b=ar[i]*2+a;
                ar[i]=b%10;
                a=b/10;
            }
            if(a>0){
                ar[i]=a;
                k=i;
            }else
                k=i-1;
                c=2;
            for(h=0;h<=k;h++){
                    if(ar[h]>=c){
                            ar[h]=ar[h]-c;
                            break;
                    }else{
            ar[h]=10+ar[h]-c;
                        c=1;
                    }
                }
              if(ar[k]>0)
              printf("%d",ar[k]);
                for(l=k-1;l>=0;l--){
                    printf("%d",ar[l]);
                }
               printf("\n");
            }
        }
    return 0;
} 
