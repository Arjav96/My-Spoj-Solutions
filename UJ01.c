#include<stdio.h>
 
int LCM(int a,int b){
	return ((a*b)/gcd(a,b));
}
 
int gcd(int a,int b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}
 
int main() {
	int i, j , index,v, A, B , x , lcm , a1 , b1;
	long long T,N,y;
	scanf("%lld",&T);
	
	while(T--){
		scanf("%d%d%lld",&A,&B,&N);
		lcm = LCM(A,B);
		a1=lcm/A, b1=lcm/B;
		int pos[a1+b1],val[a1+b1];		
		index=0,v=0;
		i=1,j=1;
		while(i*A!=j*B){
			if(i*A<j*B){
				pos[index] = A;
				val[v] = i;
				v++; index++;
				i++;
				
				
			} else  {
				pos[index] = B;
				val[v] = j;
				v++;index++;
				j++;
				
			}
		}
		x = N % (a1+b1-1);
	 	y =N / (a1+b1-1);
		//printf("%d %d %d %lld\n",x,index,v,y);
		if(!x)
		 printf("%lld\n",lcm*y);
		else if(pos[x-1]==A)
		 printf("%lld\n",(A*(((a1)*y)+val[x-1])));
		else
		 printf("%lld\n",(B*(((b1)*y)+val[x-1])));
	}
	return 0;
} 
