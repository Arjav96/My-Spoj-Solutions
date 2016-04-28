 #include <iostream>
    #include <cstdio>
    #define gc getchar_unlocked
    using namespace std;
     
    void scanint(int &x)
    {
        register int c = gc();
        x = 0;
        for(;(c<48 || c>57);c = gc());
        for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    }
     
    int main() {
    	int n;
    	scanint(n);
    	char str1[1010],str2[1010];
    	int a1[1010],a2[1010];
    	scanf("%s%s",str1,str2);
    	for(int i=0;i<n;++i){
    		if(str1[i]=='A')
    			a1[i]=1;
    		else if(str1[i]=='U')
    			a1[i]=2;
    		else if(str1[i]=='C')
    			a1[i]=3;
    		else
    			a1[i]=4;
    	}
    	
    	for(int i=0;i<n;++i){
    		if(str2[i]=='A')
    			a2[i]=1;
    		else if(str2[i]=='U')
    			a2[i]=2;
    		else if(str2[i]=='C')
    			a2[i]=3;
    		else
    			a2[i]=4;
    	}
    	
    	int dp[1003][1003] = {0};
    	
    	for(int i=0;i<n;++i){
    		if(a1[0] == a2[i])
    			dp[0][i] = 1;
    		else
    			dp[0][i] = 0;
    		//cout<<dp[0][i]<<" ";
    	}
    	//cout<<"\n";
    	for(int i=0;i<n;++i){
    		if(a1[i] == a2[0])
    			dp[i][0] = 1;
    		else
    			dp[i][0] = 0;
    		//cout<<dp[i][0]<<" ";
    	}
    	//cout<<"\n\n";
    	for(int i=1;i<n;++i){
    		for(int j=1;j<n;++j){
    			if(a1[i] == a2[j])
    				dp[i][j]++;
    			dp[i][j] += dp[i-1][j-1];
    			//cout<<dp[i][j]<<" ";
    		}
    		//cout<<"\n";
    	}
    	long q;
    	scanf("%ld",&q);
    	int x,y,l,cnt;
    	for(int i=0;i<q;++i){
    		scanint(x);
    		scanint(y);
    		scanint(l);
    		if(x == 1 || y == 1){
    			printf("%d\n",dp[x+l-2][y+l-2]);
    			continue;
    		}
    		printf("%d\n",(dp[x+l-2][y+l-2] - dp[x-2][y-2]));
    	}
    	return 0;
    }  
