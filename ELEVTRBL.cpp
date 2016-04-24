#include <bits/stdc++.h>
using namespace std;
#define S(t) scanf("%d",&(t))
#define P(t) printf("%d\n",t);
 
struct node{
	int floor;
	int steps;
};
struct node Newfloor(int floor, int step){
	struct node n;
	n.floor = floor;
	n.steps = step;
	return n;
}
bool vis[1000003];
int main(){
	int f,s,g,u,d,i=-1;
	S(f);S(s);S(g);S(u);S(d);
	queue<struct node> Q;
	Q.push(Newfloor(s,0));
	while(!Q.empty()){
		node *fr = &(Q.front());
		Q.pop();
		if(fr->floor == g){
			i = fr->steps;
			break;
		}
		if(fr->floor+u <= f && !vis[fr->floor+u]){
			vis[fr->floor + u]  = true;
			Q.push(Newfloor(fr->floor+u,fr->steps+1));
		}
		if(fr->floor-d >= 1 && !vis[fr->floor-d]){
			vis[fr->floor-d] = true;
			Q.push(Newfloor(fr->floor-d,fr->steps+1));
		}
	}
	if(i==-1) printf("use the stairs");
	else P(i);
} 
