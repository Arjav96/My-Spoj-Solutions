#include <iostream>
#include <cstdio>
#define MAX_VALUE 1000000001
using namespace std;
 
void constructTree(long input[],long segTree[],int low,int high,int pos){
	if(low==high){
		segTree[pos] = input[low];
		return ;
	}	
	int mid = (low+high)/2;
	constructTree(input,segTree,low,mid,2*pos+1);
	constructTree(input,segTree,mid+1,high,2*pos+2);
	segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
}
 
long RangeMaxQuery(long segTree[],int qlow,int qhigh,int low,int high,int pos){
	if(qlow<=low && qhigh>=high)		//total overlap
		return segTree[pos];
	if(qlow>high || qhigh <low )		// no overlap
		return MAX_VALUE;
	int mid = (low+high)/2;				//partial overlap
	return min(RangeMaxQuery(segTree,qlow,qhigh,low,mid,2*pos + 1),RangeMaxQuery(segTree,qlow,qhigh,mid+1,high,2*pos +2));
}
 
int getSegmentTreeSize(int N) {
	int size = 1;
	for (; size < N; size <<= 1);
	return size << 1;
}
 
int main() {
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;++j){
	int N,Q;
	scanf("%d%d",&N,&Q);
	int k = getSegmentTreeSize(N);
	long input[N+10],stree[k + 10];
	for(int i=0;i<N;++i)
		scanf("%ld",&input[i]);
	int x,y;
	long int min;
	constructTree(input,stree,0,N-1,0);
	printf("Scenario #%d:\n\n",j+1);
	for(int i=0;i<Q;++i){
		scanf("%d%d",&x,&y);
		min = RangeMaxQuery(stree,x - 1,y - 1,0,N-1,0);
		printf("%ld\n",min);
	}
	}
	return 0;
} 
