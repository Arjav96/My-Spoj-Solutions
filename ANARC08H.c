// Musical chairs: N -no of players, D - position remover
 
 
#include <stdio.h>
int solve(int n, int k) {
int r = 0,i;
for (i = 2; i <= n; i++)
r = (r + k) % i;
return r+1;
}
int main(void) {
int N,D,W;
scanf("%d",&N);
scanf("%d",&D);
while(N&&D){
W=solve(N,D);
printf("%d %d %d\n",N,D,W);
scanf("%d",&N);
scanf("%d",&D);
}
return 0;
} 
