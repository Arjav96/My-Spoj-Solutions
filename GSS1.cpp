//Left: the best sum you can obtain provided the subarray starts from the leftmost index in the interval.
//Right: the best sum you can obtain provided the subarray ends at the rightmost index in the interval.
//Best: The largest subarray sum you can have in an interval.
//Sum: Sum of all elements in the interval.
 
#include <iostream>
#include <cstdio>
using namespace std;
 
struct node{
	long left;
	long right;
	long sum;
	long best;
};
long input[50003];
node tree[200003];
 
node makeNode(long sum, long best, long left, long right) {
    node tmp;
    tmp.sum = sum;
    tmp.best = best;
    tmp.left = left;
    tmp.right = right;
    return tmp;
}
 
node combine (node l, node r) {
    long left = l.left;
    if (l.sum + r.left>left) left =l.sum + r.left;
    long right = r.right;
    if (r.sum + l.right > right) right = r.sum + l.right;
    long best = max(l.right + r.left, max(l.best, r.best));
    return makeNode(l.sum+r.sum,best, left, right);
}
 
 
node build(int from, int to, int index) {
    if (from == to) {
        tree[index] = makeNode(input[from], input[from], input[from], input[from]);
        return tree[index];
    }
    int mid = (from+to)/2;
    node l = build(from,mid, (index<<1));
    node r = build(mid+1,to, (index<<1)+1);
 
    tree[index] = combine(l,r);
    return tree[index];
}
 
node ans(int index, int from, int to, int a, int b) {
    if (from == a && to == b) {
        return tree[index];
    }
    int mid = (from+to)/2;
    if (b <= mid) {
        return ans((index<<1), from, mid, a, b);
    }
    if (a > mid) {
        return ans((index<<1) + 1, mid+1,to,a,b);
    }
    node l = ans((index<<1), from, mid, a, mid);
    node r = ans((index<<1) + 1, mid+1,to,mid+1,b);
    return combine(l,r);
}
 
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%ld",&input[i]);
	int M;
	scanf("%d",&M);
	int x,y;
	
	build(1,N,1);
	//for(int i=0;i<=4*n;++i)
	//	printf("%d ", tree[i]);
	for(int i=0;i<M;++i){
		scanf("%d%d",&x,&y);
		printf("%ld\n",ans(1,1,N,x,y).best);
	}
	return 0;
} 
