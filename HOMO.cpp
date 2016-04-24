#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
 
int main() {
	map <long long,long long> M;
	long n;
	scanf("%ld",&n);
	char s[10] ;
	char ins[] = "insert";
	long long k;
	long long homo=0,hetr=0;
	while(n--){
		//printf("1\n");
		scanf("%s%lld",s,&k);
		if(strcmp(s,ins) == 0){
			M[k] += 1;
			if(M[k] == 2)
				homo++;
			else if(M[k] == 1)
				hetr++;
		}
		else {
			if(M[k] > 0){
				M[k] -= 1;
				if(M[k] == 1)
					homo--;
				else if(M[k] == 0)
					hetr--;
				
			}
		}
		//printf("1\n");
		if(homo>=1 && hetr>=2)
			printf( "both\n" );
		else if ( homo >= 1 ) 
            printf( "homo\n" );
        else if ( hetr >= 2 ) 
            printf( "hetero\n" );
        else 
            printf( "neither\n" );
        
	}
	return 0;
} 
