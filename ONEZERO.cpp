/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * Created By : Arjav Jain
 * CSE, MNNIT-ALLAHABAD 
 * vampire18
 _._._._._._._._._._._._._._._._._._._._._.*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define PER(i,a,b) for(int i=b;i>=a;--i)
#define X first
#define Y second
#define all(c) c.begin(),c.end() //eg sort(all(v));
 
#define tr(c, itr) for(itr = (c).begin(); itr != (c).end(); itr++)
#define present(container, element) (container.find(element) != container.end()) //for set,map,etc
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vectors
 
typedef long long ll;
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef pair< int,int > ii; 
 
#define sz(a) int((a).size())
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))
 
//i/o
#define sc(n) scanf("%d",&n)
#define sc2(n,m) scanf("%d%d",&n,&m)
#define scs(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define scc(n) scanf("%c",&n)
 
#define scll(n) scanf("%lld",&n)
#define scll2(n,m) scanf("%lld%lld",&n,&m)
#define outll(n) printf("%lld\n",n)
#define outll2(n,m) printf("%lld %lld\n",n,m)
 
//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 20100
 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
 
int parent[MAX],cur,tmp,val[MAX]; 
queue<int> q;
void bfs_backtrack(int n){
	q.push(1);
	parent[1] = 0;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur == 0){
			stack<int> S;
			while(parent[cur]){
				S.push(val[cur]);
				cur = parent[cur];
			}
			S.push(1);
			while(!S.empty()){
				printf("%d",S.top());
				S.pop();
			}
			printf("\n");
			break;
		}
		tmp = (cur * 10) % n;
		if(parent[tmp] == -1){
			q.push(tmp);
			val[tmp] = 0;
			parent[tmp] = cur;
		}
		tmp = (cur * 10 + 1) % n;
		if(parent[tmp] == -1){
			q.push(tmp);
			val[tmp] = 1;
			parent[tmp] = cur;
		}
	}
}
 
int main(){
	int t,n;
	sc(t);
	while(t--){
		while(!q.empty()){
			q.pop();
		}
		ini(parent);
		sc(n);
		bfs_backtrack(n);
	}
} 
