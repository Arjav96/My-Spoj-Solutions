#include <bits/stdc++.h>
using namespace std;
 
int main(){
	char s1[53],s2[53],c;
	int len1,len2,dp[53][53],max=0,l1,l2;
	while((c = getchar()) != EOF){
		s1[0] = c;
		l1=0;l2=0;
		while((c = getchar()) != '\n')
			s1[++l1] = c;
		s1[++l1] = '\0';
		//getchar();
		while((c = getchar()) != '\n')
			s2[l2++] = c;
		s2[l2++] = '\0';
		//scanf ("%[^\n]%*c",s1);
		//printf("%s\n%s\n",s1,s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		memset(dp,0,sizeof(dp));
		max = 0;
		for(int i=0;i<len1;++i){
			for(int j=0;j<len2;++j){
				if(i == 0){
					if(s1[i] == s2[j])
						dp[i][j] += 1;
					
				}
				else if(j == 0){
					if(s1[i] == s2[j])
						dp[i][j] += 1;
					
				}
				
				else if(s1[i] == s2[j]){
					dp[i][j] += dp[i-1][j-1] + 1;
					
				}
				
				if(max < dp[i][j])
					max = dp[i][j];
				//printf("%d ",dp[i][j]);
			}
			//printf("\n");
		}
		printf("%d\n",max);
	}
} 
