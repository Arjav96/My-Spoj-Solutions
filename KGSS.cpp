//max_data : max num found till.
//max_sum : max sum found till.
 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
struct node{
	long max_data;
	long max_sum;
};
long input[100003];
node tree[400003];
 
node makeNode(long max_data, long max_sum) {
    node tmp;
    tmp.max_data = max_data;
    tmp.max_sum = max_sum;
    return tmp;
}
 
node combine (node l, node r) {								//***Combining nodes
    long num1 = l.max_data, num2 = r.max_data ;
    long max_data = (num1 > num2) ? num1 : num2 ;
    long sum1 = l.max_sum, sum2 = r.max_sum;
    long max_sum = max(max(sum1 , sum2), (num1 + num2));
    return makeNode(max_data , max_sum);
}
 
 
node build(int from, int to, int index) {
    if (from == to) {
        tree[index] = makeNode(input[from] , input[from]);
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
        return ans((index<<1) + 1, mid+1, to, a, b);
    }
    node l = ans((index<<1), from, mid, a, mid);
    node r = ans((index<<1) + 1, mid+1,to,mid+1,b);
    return combine(l,r);
}
 
void update(int from, int to, int index, int indexMod) {
    if (from == to && from == indexMod) {
        tree[index] = makeNode(input[from], input[from]);
        return;
    }
    int mid = (from+to)/2;
    if (indexMod <= mid) {
        update(from, mid, (index<<1), indexMod);
    } else {
        update(mid+1, to, (index<<1)+1, indexMod);
    }
    tree[index] = combine(tree[index<<1],tree[(index<<1)+1]);
}
 
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%ld",&input[i]);
	int M;
	scanf("%d",&M);
	char x;
	int y,z;
	
	build(1,N,1);
	//for(int i=0;i<=4*n;++i)
	//	printf("%d ", tree[i]);
	for(int i=0;i<M;++i){
		scanf(" %c",&x);	//scanf("%*c%c",&x);	//cin>>x;	
		scanf("%d%d",&y,&z);
		//cout<<x<<" "<<y<< " "<<z <<"\n";
		if(x == 'Q')
			printf("%ld\n",ans(1,1,N,y,z).max_sum);
		else{
			input[y] = z;
			update(1,N,1,y);
		}
	}
	return 0;
} 
