#include<iostream>
#include<set>
#include<cstdio>
#include<vector>
using namespace std;
 
vector<int> V(10000000,0);
 
int main(){
    int T,N;
    long long Entry,Exit;
    set<long long> S;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%lld%lld",&Entry,&Exit);
            S.insert(Entry);
            S.insert(Exit);
            V[Entry]=1;
            V[Exit]=-1;
        }
        int max=0,sum=0;
        set<long long>::iterator it;
        for(it=S.begin();it!=S.end();it++){
            sum += V[*it];
            if(sum>max) max=sum;
            V[*it]=0;
        }
        printf("%d\n",max);
        S.clear();
    }
    return 0;
}
