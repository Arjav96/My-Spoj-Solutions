  #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    using namespace std;
  
    int main() {
    	char str[1000010];
    	long cnt = 0;
    	scanf("%s",str);
    	long len = strlen(str); 
		long lastcnt[5] = {0};
		int a[1000010];
    	for(long i=0;i < len;++i){
    		if(str[i]=='1')
    			a[i]=1;
    		else if(str[i]=='8')
    			a[i]=2;
    		else if(str[i]=='0')
    			a[i]=3;
    		else
    			a[i]=4;
    	}
    	
    	long x=0;
    	
    	for(x=0;x<len;++x){
    		if(a[x] == 1)
    			break;
    	}
    	
    	for(long i = x ; i < len ; ++i){
    		
    		if(i == x){
    			cnt = 1;
    			lastcnt[1] = 1;
    			//cout << "!" << cnt <<"\n";
    			continue;
    		}
    		
    		if(a[i] < a[i-1]){
    				cnt = lastcnt[a[i]];
				if(a[i-1] >= 3 && a[i] == 1){
					lastcnt[1]++;
					cnt = lastcnt[1];
					continue;
				}
				
    			if(!lastcnt[a[i]]){
    				if(a[i] == 3){
    					if(!lastcnt[2]){
    						lastcnt[3] = 0;
    						continue;
    					}
    				lastcnt[3] = lastcnt[2] + 1;
    				cnt = lastcnt[3];
    				}
    				else{
    					lastcnt[a[i]] = lastcnt[a[i]-1] + 1;
    					cnt = lastcnt[a[i]];
    				}
    			}
				
    			else{
    				cnt = max(lastcnt[a[i]],lastcnt[a[i]-1]);	//err
    				cnt++;
    				lastcnt[a[i]] = cnt;
    			}
    			//cout << "@" << cnt <<"\n";
    		}
    		
    		else if((a[i] - a[i-1]) <= 1){
    			cnt = max(lastcnt[a[i-1]],lastcnt[a[i]]);	//err
    			
    			
    			if(cnt > 0){
    				cnt++;
    				lastcnt[a[i]] = cnt;
    			}
    			//cout << "#" << cnt <<"\n";
    		}
    		
    		else if((a[i] - a[i-1]) > 1){
    			if((a[i] - a[i-1] == 3)){		//a[i-1] = 1
    				if(!lastcnt[2] || !lastcnt[3]){
    					lastcnt[4] = 0;
    					if(!lastcnt[2]){
    						cnt = lastcnt[1];
    					}
    					else if(!lastcnt[3]){
    						cnt = lastcnt[2];
    					}
    				}
    				else{
    					lastcnt[4] = max(lastcnt[3],lastcnt[4]) + 1;	//err
    					cnt = lastcnt[4];
    				}
    				
    				
    			}
    			else{
    			 	if(!lastcnt[a[i-1] + 1]){
						lastcnt[a[i]] = 0;
						cnt = lastcnt[a[i-1]];
    			 	}
    			 	else{
    			 		cnt = max(lastcnt[a[i] - 1],lastcnt[a[i]]) + 1;	//err
    			 		lastcnt[a[i]] = cnt;
    			 	}
				}
    			//cout << "$" << cnt <<"\n";
    		
    		}
    		//cout<<"***"<<lastcnt[1]<<" "<<lastcnt[2]<<" "<<lastcnt[3]<<" "<<lastcnt[4]<<"\n";
    	}
    	if(lastcnt[1] != 0 && lastcnt[2] != 0 && lastcnt[3] != 0 && lastcnt[4] != 0)
    		printf("%ld\n",lastcnt[4]);
    	else
    		printf("0\n");
    	return 0;
    }  
