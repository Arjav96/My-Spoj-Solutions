#include<stdio.h>
 
int main(){
int T,i;
long int E,N,tmp,maxteams;
 
scanf("%d",&T);
for(i=1;i<=T;i++){
	maxteams = 0;
	scanf("%ld%ld",&E,&N);
	if(E<N){
		tmp = E;
		E = N; 
		N = tmp;
	}
	
	if(E >= (2*N)){
		maxteams = N;
		printf("%ld\n",maxteams);
		continue;	
	}
 
	
	while(E!=0 && N!=0){
		if(E==1 && N==1)
			break;
		
		if(E==N){
			if(E%3==0||E%3==1)
				maxteams += (2*(E/3));
			else
				maxteams += ((2*(E/3)) + 1);
			break;
		}	
 
		while(E>N && N!=0){	//needs to optimise
			E -= 2;
			N -=1;
			maxteams++;
				
		}
				
		while(E<N && E!=0){	//needs to optimise
			N -= 2;
			E -= 1;
			maxteams++;
			
		}
		
	}
	
printf("%ld\n",maxteams);
}
return 0;
 
 
} 
